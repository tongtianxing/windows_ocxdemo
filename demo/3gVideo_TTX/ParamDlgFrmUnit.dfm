object ParamDlgFrm: TParamDlgFrm
  Left = 334
  Top = 247
  BorderStyle = bsDialog
  Caption = #21442#25968#37197#32622
  ClientHeight = 330
  ClientWidth = 395
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 6
    Top = 5
    Width = 385
    Height = 284
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #37197#32622
      object Label2: TLabel
        Left = 233
        Top = 228
        Width = 52
        Height = 13
        Caption = #30721#27969#31867#22411
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        Visible = False
      end
      object Label3: TLabel
        Left = 221
        Top = 249
        Width = 65
        Height = 13
        Caption = #35270#39057#27969#27169#24335
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        Visible = False
      end
      object SpeedButton1: TSpeedButton
        Left = 312
        Top = 77
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000CE0E0000C40E00001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          77777777777777777777000000000007777700333333333077770B0333333333
          07770FB03333333330770BFB0333333333070FBFB000000000000BFBFBFBFB07
          77770FBFBFBFBF0777770BFB0000000777777000777777770007777777777777
          7007777777770777070777777777700077777777777777777777}
        OnClick = SpeedButton1Click
      end
      object LabeledEditIP: TLabeledEdit
        Left = 189
        Top = 15
        Width = 121
        Height = 21
        EditLabel.Width = 65
        EditLabel.Height = 13
        EditLabel.Caption = #35270#39057#26381#21153#22120
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = #23435#20307
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        LabelPosition = lpLeft
        ParentFont = False
        TabOrder = 0
      end
      object LabeledEditPort: TLabeledEdit
        Left = 189
        Top = 44
        Width = 121
        Height = 21
        EditLabel.Width = 104
        EditLabel.Height = 13
        EditLabel.Caption = #35270#39057#26381#21153#22120#31471#21475#21495
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = #23435#20307
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        LabelPosition = lpLeft
        ParentFont = False
        TabOrder = 1
      end
      object LabeledEditStreamIP: TLabeledEdit
        Left = 8
        Top = 226
        Width = 121
        Height = 21
        EditLabel.Width = 78
        EditLabel.Height = 13
        EditLabel.Caption = #27969#23186#20307#26381#21153#22120
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = #23435#20307
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        LabelPosition = lpLeft
        ParentFont = False
        TabOrder = 2
        Visible = False
      end
      object LabeledEditStreamPort: TLabeledEdit
        Left = 8
        Top = 247
        Width = 121
        Height = 21
        EditLabel.Width = 117
        EditLabel.Height = 13
        EditLabel.Caption = #27969#23186#20307#26381#21153#22120#31471#21475#21495
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = #23435#20307
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        LabelPosition = lpLeft
        ParentFont = False
        TabOrder = 3
        Visible = False
      end
      object cbxStreamType: TComboBox
        Left = 288
        Top = 224
        Width = 121
        Height = 21
        Style = csDropDownList
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        ItemHeight = 13
        ItemIndex = 0
        ParentFont = False
        TabOrder = 4
        Text = #20027#30721#27969
        Visible = False
        Items.Strings = (
          #20027#30721#27969
          #23376#30721#27969)
      end
      object cbxStreamMode: TComboBox
        Left = 288
        Top = 245
        Width = 121
        Height = 21
        Style = csDropDownList
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        ItemHeight = 13
        ItemIndex = 1
        ParentFont = False
        TabOrder = 5
        Text = 'TCP'
        Visible = False
        Items.Strings = (
          'UDP'
          'TCP')
      end
      object LabeledEditCutPicFilePath: TLabeledEdit
        Left = 96
        Top = 77
        Width = 214
        Height = 21
        EditLabel.Width = 87
        EditLabel.Height = 13
        EditLabel.Caption = #35270#39057#25130#22270#36335#24452':    '
        LabelPosition = lpLeft
        TabOrder = 6
      end
      object lbledtCloseTime: TLabeledEdit
        Left = 189
        Top = 109
        Width = 120
        Height = 21
        EditLabel.Width = 105
        EditLabel.Height = 13
        EditLabel.Caption = #33258#21160#20851#38381#26102#38271'('#31186'):    '
        LabelPosition = lpLeft
        TabOrder = 7
        OnChange = lbledtCloseTimeChange
      end
    end
  end
  object BtnQD: TBitBtn
    Left = 236
    Top = 297
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 1
    Kind = bkOK
  end
  object BtnQX: TBitBtn
    Left = 315
    Top = 297
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 2
    Kind = bkCancel
  end
end
