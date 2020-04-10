object FrmDownLoadByTime: TFrmDownLoadByTime
  Left = 372
  Top = 203
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #25353#26102#38388#27573#19979#36733
  ClientHeight = 204
  ClientWidth = 453
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel4: TPanel
    Left = 0
    Top = 160
    Width = 453
    Height = 44
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 0
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 451
      Height = 41
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object BtnCancel: TBitBtn
        Left = 338
        Top = 9
        Width = 88
        Height = 25
        Cancel = True
        Caption = #21462#28040
        ModalResult = 2
        TabOrder = 0
        OnClick = BtnCancelClick
        Glyph.Data = {
          DE010000424DDE01000000000000760000002800000024000000120000000100
          0400000000006801000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          333333333333333333333333000033338833333333333333333F333333333333
          0000333911833333983333333388F333333F3333000033391118333911833333
          38F38F333F88F33300003339111183911118333338F338F3F8338F3300003333
          911118111118333338F3338F833338F3000033333911111111833333338F3338
          3333F8330000333333911111183333333338F333333F83330000333333311111
          8333333333338F3333383333000033333339111183333333333338F333833333
          00003333339111118333333333333833338F3333000033333911181118333333
          33338333338F333300003333911183911183333333383338F338F33300003333
          9118333911183333338F33838F338F33000033333913333391113333338FF833
          38F338F300003333333333333919333333388333338FFF830000333333333333
          3333333333333333333888330000333333333333333333333333333333333333
          0000}
        NumGlyphs = 2
      end
      object BtnOk: TBitBtn
        Left = 239
        Top = 9
        Width = 84
        Height = 25
        Caption = #30830#23450
        Default = True
        TabOrder = 1
        OnClick = BtnOkClick
        Glyph.Data = {
          DE010000424DDE01000000000000760000002800000024000000120000000100
          0400000000006801000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          3333333333333333333333330000333333333333333333333333F33333333333
          00003333344333333333333333388F3333333333000033334224333333333333
          338338F3333333330000333422224333333333333833338F3333333300003342
          222224333333333383333338F3333333000034222A22224333333338F338F333
          8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
          33333338F83338F338F33333000033A33333A222433333338333338F338F3333
          0000333333333A222433333333333338F338F33300003333333333A222433333
          333333338F338F33000033333333333A222433333333333338F338F300003333
          33333333A222433333333333338F338F00003333333333333A22433333333333
          3338F38F000033333333333333A223333333333333338F830000333333333333
          333A333333333333333338330000333333333333333333333333333333333333
          0000}
        NumGlyphs = 2
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 41
    Width = 453
    Height = 119
    Align = alClient
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 1
    object lbl1: TLabel
      Left = 94
      Top = 37
      Width = 59
      Height = 13
      Caption = #26102#38388#27573' '#20174
    end
    object lbl2: TLabel
      Left = 138
      Top = 61
      Width = 13
      Height = 13
      Caption = #21040
    end
    object TmBeg: TDateTimePicker
      Left = 259
      Top = 32
      Width = 90
      Height = 21
      Date = 38122.000000000000000000
      Time = 38122.000000000000000000
      Kind = dtkTime
      TabOrder = 0
    end
    object TmEnd: TDateTimePicker
      Left = 259
      Top = 56
      Width = 90
      Height = 21
      Date = 38122.999988425930000000
      Time = 38122.999988425930000000
      Kind = dtkTime
      TabOrder = 1
    end
    object DtEnd: TDateTimePicker
      Left = 159
      Top = 56
      Width = 98
      Height = 21
      Date = 38122.000000000000000000
      Time = 38122.000000000000000000
      TabOrder = 2
    end
    object DtBeg: TDateTimePicker
      Left = 159
      Top = 32
      Width = 98
      Height = 21
      Date = 38122.000000000000000000
      Time = 38122.000000000000000000
      TabOrder = 3
    end
  end
  object Panel8: TPanel
    Left = 0
    Top = 0
    Width = 453
    Height = 41
    Align = alTop
    BevelInner = bvLowered
    BevelOuter = bvNone
    Caption = #25353#26102#38388#27573#19979#36733
    Color = 15265488
    Font.Charset = GB2312_CHARSET
    Font.Color = 16512
    Font.Height = -16
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
end
