unit IntegerListUnit;

interface

uses
  Classes,
  Types,
  SysUtils;

resourcestring
  SDuplicateInteger = 'Integer list does not allow duplicates';

type
  TGeoClasses=class
  public
    class function IntDynAryToString(ADynAry: TIntegerDynArray;const ADelimit:String):string;
  end;

  EIntegerListError = class(Exception);

  TIntegers=class(TPersistent)
  private
    FUpdateCount: Integer;
    FDelimiter: Char;
    procedure ReadData(Reader: TReader);
    procedure WriteData(Writer: TWriter);
    procedure SetDelimiter(const Value: Char);
    function  GetTextStr: string;
    procedure SetTextStr(const Value: string);
  protected
    procedure DefineProperties(Filer: TFiler); override;
    procedure Error(const Msg: string; Data: Integer); overload;
    procedure Error(Msg: PResStringRec; Data: Integer); overload;
    function  Get(Index: Integer): Integer; virtual; abstract;
    function  GetCapacity: Integer; virtual;
    function  GetCount: Integer; virtual; abstract;
    function  GetData(Index: Integer): Pointer; virtual;
    procedure Put(Index: Integer; I: Integer); virtual;
    procedure PutData(Index: Integer; AData: Pointer); virtual;
    procedure SetCapacity(NewCapacity: Integer); virtual;
    procedure SetUpdateState(Updating: Boolean); virtual;
    function  CompareIntegers(const I1, I2: Integer): Integer; virtual;
    property  UpdateCount: Integer read FUpdateCount;
  public
    function  Add(const I: Integer): Integer; virtual;
    function  AddData(const I: Integer; AData: Pointer): Integer; virtual;
    procedure Append(const I: Integer);
    procedure AddIntegers(Integers: TIntegers); virtual;
    procedure Assign(Source: TPersistent); override;
    procedure BeginUpdate;
    procedure Clear; virtual; abstract;
    procedure Delete(Index: Integer); virtual; abstract;
    function  Remove(const I: Integer):Integer;virtual;
    procedure EndUpdate;
    function  Equals(Integers: TIntegers): Boolean;
    procedure Exchange(Index1, Index2: Integer); virtual;
    function  IndexOf(const I: Integer): Integer; virtual;
    function  IndexOfData(AData: Pointer): Integer; virtual;
    procedure Insert(Index: Integer; const I: Integer); virtual; abstract;
    procedure InsertData(Index: Integer; const I: Integer;  AData: Pointer); virtual;
    procedure LoadFromFile(const FileName: string); virtual;
    procedure LoadFromStream(Stream: TStream); virtual;
    procedure Move(CurIndex, NewIndex: Integer); virtual;
    procedure SaveToFile(const FileName: string); virtual;
    procedure SaveToStream(Stream: TStream); virtual;
    property  Capacity: Integer       read GetCapacity write SetCapacity;
    property  Count: Integer          read GetCount;
    property  Delimiter: Char         read FDelimiter  write SetDelimiter;
    property  Text: string            read GetTextStr  write SetTextStr;
    property  Datas[Index: Integer]: Pointer    read GetData write PutData;
    property  Integers[Index: Integer]: Integer read Get write Put; default;

  end;

{ TIntegerList class }

  TIntegerList = class;

  PIntegerItem = ^TIntegerItem;
  TIntegerItem = record
    FInteger: Integer;
    FData: Pointer;
  end;

  PIntegerItemList = ^TIntegerItemList;
  TIntegerItemList = array[0..MaxListSize] of TIntegerItem;
  TIntegerListSortCompare = function(List: TIntegerList; Index1, Index2: Integer): Integer;

  TIntegerList = class(TIntegers)
  private
    FList: PIntegerItemList;
    FCount: Integer;
    FCapacity: Integer;
    FSorted: Boolean;
    FDuplicates: TDuplicates;
    FOnChange: TNotifyEvent;
    FOnChanging: TNotifyEvent;
    procedure ExchangeItems(Index1, Index2: Integer);
    procedure Grow;
    procedure QuickSort(L, R: Integer; SCompare: TIntegerListSortCompare);
    procedure InsertItem(Index: Integer; const I: Integer);
    procedure SetSorted(Value: Boolean);
  protected
    procedure Changed; virtual;
    procedure Changing; virtual;
    function Get(Index: Integer): Integer; override;
    function GetCapacity: Integer; override;
    function GetCount: Integer; override;
    function GetData(Index: Integer): Pointer; override;
    procedure Put(Index, I: Integer); override;
    procedure PutData(Index: Integer; AData: Pointer); override;
    procedure SetCapacity(NewCapacity: Integer); override;
    procedure SetUpdateState(Updating: Boolean); override;
  public
    constructor Create;// override;
    destructor Destroy; override;
    function Add(const I: Integer): Integer; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Exchange(Index1, Index2: Integer); override;
    function Find(const I: Integer; var Index: Integer): Boolean; virtual;
    function IndexOf(const I: Integer): Integer; override;
    procedure Insert(Index: Integer; const I: Integer); override;
    procedure Sort; virtual;
    procedure CustomSort(Compare: TIntegerListSortCompare); virtual;
    property Duplicates: TDuplicates read FDuplicates write FDuplicates;
    property Sorted: Boolean read FSorted write SetSorted;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnChanging: TNotifyEvent read FOnChanging write FOnChanging;
  end;

implementation
uses
  {$IFDEF DELPHI5}
  Consts
  {$ELSE}
  RTLConsts
  {$ENDIF}
  ;
{ TGeoClasses }

class function TGeoClasses.IntDynAryToString(ADynAry: TIntegerDynArray;
  const ADelimit: String): string;
var
  I: Integer;
begin
  Result := '';
  if Length(ADynAry) = 0 then Exit;
  Result := IntToStr(ADynAry[0]);
  for I := 1 to Length(ADynAry) - 1 do    // Iterate
    Result := Result + ADelimit + IntToStr(ADynAry[i]);
end;

{ TIntegers }

function TIntegers.Add(const I: Integer): Integer;
begin
  Result := GetCount;
  Insert(Result, I);
end;

function TIntegers.AddData(const I: Integer; AData: Pointer): Integer;
begin
  Result := Add(I);
  PutData(Result, AData);
end;

procedure TIntegers.AddIntegers(Integers: TIntegers);
var
  I: Integer;
begin
  BeginUpdate;
  try
    for I := 0 to Integers.Count - 1 do
      AddData(Integers[I], Integers.Datas[I]);
  finally
    EndUpdate;
  end;
end;

procedure TIntegers.Append(const I: Integer);
begin
  Add(I);
end;

procedure TIntegers.Assign(Source: TPersistent);
begin
  if Source is TIntegers then
  begin
    BeginUpdate;
    try
      Clear;
      FDelimiter := TIntegers(Source).FDelimiter;
      AddIntegers(TIntegers(Source));
    finally
      EndUpdate;
    end;
    Exit;
  end;
  inherited Assign(Source);
end;

procedure TIntegers.BeginUpdate;
begin
  if FUpdateCount = 0 then SetUpdateState(True);
  Inc(FUpdateCount);
end;

function TIntegers.CompareIntegers(const I1, I2: Integer): Integer;
begin
  Result := I1 - I2;
end;

procedure TIntegers.DefineProperties(Filer: TFiler);

  function DoWrite: Boolean;
  begin
    if Filer.Ancestor <> nil then
    begin
      Result := True;
      if Filer.Ancestor is TIntegers then
        Result := not Equals(TIntegers(Filer.Ancestor))
    end
    else Result := Count > 0;
  end;

begin
  Filer.DefineProperty('Integers', ReadData, WriteData, DoWrite);
end;

procedure TIntegers.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount = 0 then SetUpdateState(False);
end;

function TIntegers.Equals(Integers: TIntegers): Boolean;
var
  I, Count: Integer;
begin
  Result := False;
  Count := GetCount;
  if Count <> Integers.GetCount then Exit;
  for I := 0 to Count - 1 do if Get(I) <> Integers.Get(I) then Exit;
  Result := True;
end;

procedure TIntegers.Error(const Msg: string; Data: Integer);

  function ReturnAddr: Pointer;
  asm
          MOV     EAX,[EBP+4]
  end;

begin
  raise EIntegerListError.CreateFmt(Msg, [Data]) at ReturnAddr;
end;

procedure TIntegers.Error(Msg: PResStringRec; Data: Integer);
begin
  Error(LoadResString(Msg), Data);
end;

procedure TIntegers.Exchange(Index1, Index2: Integer);
var
  TempData: Pointer;
  TempInteger: Integer;
begin
  BeginUpdate;
  try
    TempInteger := Integers[Index1];
    TempData := Datas[Index1];
    Integers[Index1] := Integers[Index2];
    Datas[Index1] := Datas[Index2];
    Integers[Index2] := TempInteger;
    Datas[Index2] := TempData;
  finally
    EndUpdate;
  end;
end;

function TIntegers.GetCapacity: Integer;
begin  // descendents may optionally override/replace this default implementation
  Result := Count;
end;

function TIntegers.GetData(Index: Integer): Pointer;
begin
  Result := nil;
end;

function TIntegers.GetTextStr: string;
var
  I: Integer;
begin
  Result := '';
  if Count = 0 then Exit;
  Result := IntToStr(Get(0));
  if Count = 1 then Exit;
  for I := 1 to Count - 1 do    // Iterate
  begin
    Result := Result + Delimiter + IntToStr(I);
  end;    // for
end;

function TIntegers.IndexOf(const I: Integer): Integer;
begin
  for Result := 0 to GetCount - 1 do
    if CompareIntegers(Get(Result), I) = 0 then Exit;
  Result := -1;
end;

function TIntegers.IndexOfData(AData: Pointer): Integer;
begin
  for Result := 0 to GetCount - 1 do
    if GetData(Result) = AData then Exit;
  Result := -1;
end;

procedure TIntegers.InsertData(Index: Integer; const I: Integer;
  AData: Pointer);
begin
  Insert(Index, I);
  PutData(Index, AData);
end;

procedure TIntegers.LoadFromFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmOpenRead or fmShareDenyWrite);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TIntegers.LoadFromStream(Stream: TStream);
var
  Size: Integer;
  S: string;
begin
  BeginUpdate;
  try
    Size := Stream.Size - Stream.Position;
    SetString(S, nil, Size);
    Stream.Read(Pointer(S)^, Size);
    SetTextStr(S);
  finally
    EndUpdate;
  end;
end;

procedure TIntegers.Move(CurIndex, NewIndex: Integer);
var
  TempData: Pointer;
  TempInteger: Integer;
begin
  if CurIndex <> NewIndex then
  begin
    BeginUpdate;
    try
      TempInteger := Get(CurIndex);
      TempData := GetData(CurIndex);
      Delete(CurIndex);
      InsertData(NewIndex, TempInteger, TempData);
    finally
      EndUpdate;
    end;
  end;
end;

procedure TIntegers.Put(Index, I: Integer);
var
  TempPointer: Pointer;
begin
  TempPointer := GetData(Index);
  Delete(Index);
  InsertData(Index, I, TempPointer);
end;

procedure TIntegers.PutData(Index: Integer; AData: Pointer);
begin

end;

procedure TIntegers.ReadData(Reader: TReader);
begin
  Reader.ReadListBegin;
  BeginUpdate;
  try
    Clear;
    while not Reader.EndOfList do Add(Reader.ReadInteger);
  finally
    EndUpdate;
  end;
  Reader.ReadListEnd;
end;

function TIntegers.Remove(const I: Integer): Integer;
begin
  Result := IndexOf(I);
  if Result >= 0 then
    Delete(Result);
end;

procedure TIntegers.SaveToFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TIntegers.SaveToStream(Stream: TStream);
var
  S: string;
begin
  S := GetTextStr;
  Stream.WriteBuffer(Pointer(S)^, Length(S));
end;

procedure TIntegers.SetCapacity(NewCapacity: Integer);
begin
  // do nothing - descendents may optionally implement this method
end;

procedure TIntegers.SetDelimiter(const Value: Char);
begin
  if FDelimiter <> Value then FDelimiter := Value;
end;

procedure TIntegers.SetTextStr(const Value: string);
var
  P, Start: PChar;
  S: string;
begin
  BeginUpdate;
  try
    Clear;
    P := Pointer(Value);
    if P <> nil then
      while P^ <> #0 do
      begin
        Start := P;
        while not (P^ in [FDelimiter]) do Inc(P);
        SetString(S, Start, P - Start);
        Add(StrToIntDef(S,0));
      end;
  finally
    EndUpdate;
  end;
end;

procedure TIntegers.SetUpdateState(Updating: Boolean);
begin

end;

procedure TIntegers.WriteData(Writer: TWriter);
var
  I: Integer;
begin
  Writer.WriteListBegin;
  for I := 0 to Count - 1 do Writer.WriteString(IntToStr(Get(I)));
  Writer.WriteListEnd;
end;


{ TIntegerList }

function TIntegerList.Add(const I: Integer): Integer;
begin
  if not Sorted then
    Result := FCount
  else
    if Find(I, Result) then
      case Duplicates of
        dupIgnore: Exit;
        dupError: Error(@SDuplicateInteger,I);
      end;
  InsertItem(Result, I);
end;

procedure TIntegerList.Changed;
begin
  if (FUpdateCount = 0) and Assigned(FOnChange) then FOnChange(Self);
end;

procedure TIntegerList.Changing;
begin
  if (FUpdateCount = 0) and Assigned(FOnChanging) then FOnChanging(Self);
end;

procedure TIntegerList.Clear;
begin
  if FCount <> 0 then
  begin
    Changing;
    //Finalize(FList^[0], FCount);
    FCount := 0;
    SetCapacity(0);
    Changed;
  end;
end;

constructor TIntegerList.Create;
begin
  inherited;
//  FSorted:=true;
end;

procedure TIntegerList.CustomSort(Compare: TIntegerListSortCompare);
begin
  if not Sorted and (FCount > 1) then
  begin
    Changing;
    QuickSort(0, FCount - 1, Compare);
    Changed;
  end;
end;

procedure TIntegerList.Delete(Index: Integer);
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Changing;
  //Finalize(FList^[Index]);
  Dec(FCount);
  if Index < FCount then
    System.Move(FList^[Index + 1], FList^[Index],
      (FCount - Index) * SizeOf(TIntegerItem));
  Changed;
end;

destructor TIntegerList.Destroy;
begin
  FOnChange := nil;
  FOnChanging := nil;
  inherited Destroy;
  //if FCount <> 0 then Finalize(FList^[0], FCount);
  FCount := 0;
  SetCapacity(0);
end;

procedure TIntegerList.Exchange(Index1, Index2: Integer);
begin
  if (Index1 < 0) or (Index1 >= FCount) then Error(@SListIndexError, Index1);
  if (Index2 < 0) or (Index2 >= FCount) then Error(@SListIndexError, Index2);
  Changing;
  ExchangeItems(Index1, Index2);
  Changed;
end;

procedure TIntegerList.ExchangeItems(Index1, Index2: Integer);
var
  Temp: Integer;
  Item1, Item2: PIntegerItem;
begin
  Item1 := @FList^[Index1];
  Item2 := @FList^[Index2];
  Temp := Item1^.FInteger;
  Item1^.FInteger := Item2^.FInteger;
  Item2^.FInteger := Temp;
  Temp := Integer(Item1^.FData);
  Integer(Item1^.FData) := Integer(Item2^.FData);
  Integer(Item2^.FData) := Temp;
end;

function TIntegerList.Find(const I: Integer; var Index: Integer): Boolean;
var
  L, H, II: Integer;// , C
begin
  Result := False;
  L := 0;
  H := FCount - 1;
  while L <= H do
  begin
    II := (L + H) shr 1;
    //C := FList^[II].FInteger - I;
    //if C < 0 then L := II + 1 else
    if FList^[II].FInteger < I then L:= II +1 else
    begin
      H := II - 1;
      if FList^[II].FInteger = I then//if C = 0 then
      begin
        Result := True;
        if Duplicates <> dupAccept then L := II;
      end;
    end;
  end;
   Index := L;
end;

function TIntegerList.Get(Index: Integer): Integer;
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Result := FList^[Index].FInteger;
end;

function TIntegerList.GetCapacity: Integer;
begin
  Result := FCapacity;
end;

function TIntegerList.GetCount: Integer;
begin
  Result := FCount;
end;

function TIntegerList.GetData(Index: Integer): Pointer;
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Result := FList^[Index].FData;
end;

procedure TIntegerList.Grow;
var
  Delta: Integer;
begin
  if FCapacity > 64 then Delta := FCapacity div 4 else
    if FCapacity > 8 then Delta := 16 else
      Delta := 4;
  SetCapacity(FCapacity + Delta);
end;

function TIntegerList.IndexOf(const I: Integer): Integer;
begin
  if not Sorted then
    Result := inherited IndexOf(I)
  else
    if not Find(I, Result) then
      Result := -1;
end;

procedure TIntegerList.Insert(Index: Integer; const I: Integer);
begin
  if Sorted then Error(@SSortedListError, 0);
  if (Index < 0) or (Index > FCount) then Error(@SListIndexError, Index);
  InsertItem(Index, I);
end;

procedure TIntegerList.InsertItem(Index: Integer; const I: Integer);
begin
  Changing;
  if FCount = FCapacity then Grow;
  if Index < FCount then
    System.Move(FList^[Index], FList^[Index + 1],
      (FCount - Index) * SizeOf(TIntegerItem));
  with FList^[Index] do
  begin
    FInteger := I;
    FData := nil;
  end;
  Inc(FCount);
  Changed;
end;

procedure TIntegerList.Put(Index, I: Integer);
begin
  if Sorted then Error(@SSortedListError, 0);
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Changing;
  FList^[Index].FInteger := I;
  Changed;
end;

procedure TIntegerList.PutData(Index: Integer; AData: Pointer);
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Changing;
  FList^[Index].FData := AData;
  Changed;
end;

procedure TIntegerList.QuickSort(L, R: Integer;
  SCompare: TIntegerListSortCompare);
var
  I, J, P: Integer;
begin
  repeat
    I := L;
    J := R;
    P := (L + R) shr 1;
    repeat
      while SCompare(Self, I, P) < 0 do Inc(I);
      while SCompare(Self, J, P) > 0 do Dec(J);
      if I <= J then
      begin
        ExchangeItems(I, J);
        if P = I then
          P := J
        else if P = J then
          P := I;
        Inc(I);
        Dec(J);
      end;
    until I > J;
    if L < J then QuickSort(L, J, SCompare);
    L := I;
  until I >= R;
end;

procedure TIntegerList.SetCapacity(NewCapacity: Integer);
begin
  ReallocMem(FList, NewCapacity * SizeOf(TIntegerItem));
  FCapacity := NewCapacity;
end;

procedure TIntegerList.SetSorted(Value: Boolean);
begin
  if FSorted <> Value then
  begin
    if Value then Sort;
    FSorted := Value;
  end;
end;

procedure TIntegerList.SetUpdateState(Updating: Boolean);
begin
  if Updating then Changing else Changed;
end;

function IntegerListCompare(List: TIntegerList; Index1, Index2: Integer): Integer;
begin
  Result := List.FList^[Index1].FInteger-List.FList^[Index2].FInteger;
end;

procedure TIntegerList.Sort;
begin
  CustomSort(IntegerListCompare);
end;

end.
