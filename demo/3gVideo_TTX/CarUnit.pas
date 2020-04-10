unit CarUnit;

interface

uses
  Classes, Windows,  IntegerListUnit, 
  Graphics, SysUtils, StrUtils, ExtCtrls, StdCtrls ;

type

  TCar = class(TObject)
  private
    FId: Integer;
    FCarNo: string;
    FDevID:string;
    procedure SetId(const Value: integer);
    procedure SetCarNo(const Value: string);
    procedure SetDevID(const Value: string);
  public
    constructor Create;
    destructor Destroy; override;
    property id: integer read FId write SetId;
    property CarNo: string read FCarNo write SetCarNo;
    property DevID: string read FDevID write SetDevID;
  end;
  TCarManage = class(TObject)      
  private
    FList: TIntegerList;
    function GetCar(index: integer): TCar;
    function Getcount: integer;
    function GetItems(Index: Integer): TCar;
  public
    constructor Create;
    destructor  Destroy; override; 
    function    AddNewCar(ACarId: integer): TCar;
    function    Find(ACarId: integer): TCar;
    function    FindDevIdByCarNo(ACarNo:string): String;
    function    GetCarIndex(const ACarId: integer): integer;
    procedure Clear;
    procedure Delete(ACarId: integer);
    property Count: integer read Getcount; 
    property CarS[index: integer]: TCar read getCar;
    property Items[index: integer]: TCar read GetItems;
  end;
implementation

{ TRout }

constructor TCar.Create;
begin

end;

destructor TCar.Destroy;
begin

  inherited;
end;

procedure TCar.SetCarNo(const Value: string);
begin
  FCarNo := Value;
end;

procedure TCar.SetDevID(const Value: string);
begin
  FDevID := Value;
end;

procedure TCar.SetId(const Value: integer);
begin
  FID := Value;
end;

{ TCarManage }

function TCarManage.AddNewCar(ACarId: integer): TCar;
var
  i: integer;
  newCar: TCar;
begin
  i := FList.IndexOf(ACarId);
  if i < 0 then
  begin
    Result := TCar.Create;
    Result.id := ACarId;
    FList.AddData(ACarId, Result);
  end
  else
  begin
    Result := CarS[i];
  end;
end;

procedure TCarManage.Clear;
var
  car: TCar;
begin
  while FList.Count > 0 do
  begin
    car := Items[0];
    FList.Delete(0);
    car.Free;
  end;
end;

constructor TCarManage.Create;
begin
  FList := TIntegerList.Create;
end;

procedure TCarManage.Delete(ACarId: integer);
var
  i: integer;
  car: TCar;
begin
  i := FList.IndexOf(ACarId);
  if i >= 0 then
  begin
    car := Items[i]; 
    FList.Delete(i);
    car.Free;
  end;
end;

destructor TCarManage.Destroy;
begin

  inherited;
end;

function TCarManage.Find(ACarId: integer): TCar;
var
  TmpCar: TCar;
  i,iCnt:Integer;
begin
  Result := nil;
  iCnt:=FList.Count;
  for i:=0 to iCnt-1 do
  begin
      if Items[i].id = ACarId then
      begin
        TmpCar := Items[i];
        Result := TmpCar;
        Break;
      end;
  end;
end;

function TCarManage.FindDevIdByCarNo(ACarNo: string): String;
var
  TmpCar: TCar;
  i,iCnt:Integer;
begin
  Result := '';
  iCnt:=FList.Count;
  for i:=0 to iCnt-1 do
  begin
      if Items[i].CarNo = ACarNo then
      begin
        TmpCar := Items[i];
        Result := TmpCar.DevID;
        Break;
      end;
  end;
end;

function TCarManage.GetCar(index: integer): TCar;
begin
 
end;

function TCarManage.GetCarIndex(const ACarId: integer): integer;
begin

end;

function TCarManage.Getcount: integer;
begin
  Result :=FList.Count;
end;

function TCarManage.GetItems(Index: Integer): TCar;
begin
  Result := TCar(FList.Datas[Index]);
end;

end.
