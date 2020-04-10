unit ZipLibUnit;

interface
uses Classes, zlib, base64, ZLibExGZ;

  procedure Zip(Input, Output: TStream; Compress: Boolean);
  function ZipStr(Input: string; Compress: Boolean): string;

  function DeCompress(Input: string): string;

implementation
uses SysUtils, Windows;

procedure Zip(Input, Output: TStream; Compress: Boolean);
const
  MAXBUFSIZE = 1024*100;
var
  CS: TCompressionStream;
  DS: TDecompressionStream;
  Buf: array[0..MAXBUFSIZE-1] of byte;
  BufSize: Integer;
begin
  if Assigned(Input) and Assigned(Output) then
  begin
    if Compress then
    begin
      CS := TCompressionStream.Create(clMax, Output);
      try
        CS.CopyFrom(Input, 0);
      finally
        CS.Free;
      end;
    end else
    begin
      DS := TDecompressionStream.Create(Input);
      try
        BufSize := DS.Read(Buf, MAXBUFSIZE);
        while BufSize > 0 do
        begin
          Output.Write(Buf, BufSize);
          BufSize := DS.Read(Buf, MAXBUFSIZE);
        end;
      finally
        DS.Free;
      end;
    end;
  end;
end;

function ZipStr(Input: string; Compress: Boolean): string;
var
  InputStream, OutputStream: TStringStream;
  temp: string;
begin
  if Input = '' then Exit;
  temp := MimeDecodeString(Input);
  InputStream := TStringStream.Create(temp);
  try
    OutputStream := TStringStream.Create('');
    try
      Zip(InputStream, OutputStream, Compress);
      Result := OutputStream.DataString;
    finally
      OutputStream.Free
    end;
  finally
    InputStream.Free;
  end;
end;

function DeCompress(Input: string): string;
var
  compr: string;
begin
  try
    compr := GZDecompressStr(MimeDecodeString(Input));
    result := compr;
  finally
  end;
end;

end.
