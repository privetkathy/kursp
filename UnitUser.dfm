object FormUser: TFormUser
  Left = 0
  Top = 0
  Caption = 'FormUser'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object StringGridTours: TStringGrid
    Left = 232
    Top = 80
    Width = 320
    Height = 120
    TabOrder = 0
  end
  object EditCountry: TEdit
    Left = 112
    Top = 206
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'EditCountry'
  end
  object EditMaxPrice: TEdit
    Left = 304
    Top = 208
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'EditMaxPrice'
  end
  object BtnFilter: TButton
    Left = 168
    Top = 320
    Width = 75
    Height = 25
    Caption = 'BtnFilter'
    TabOrder = 3
  end
  object BtnSortPrice: TButton
    Left = 360
    Top = 304
    Width = 75
    Height = 25
    Caption = 'BtnSortPrice'
    TabOrder = 4
  end
  object BtnBook: TButton
    Left = 192
    Top = 376
    Width = 75
    Height = 25
    Caption = 'BtnBook'
    TabOrder = 5
  end
  object BtnLogout: TButton
    Left = 344
    Top = 376
    Width = 75
    Height = 25
    Caption = 'BtnLogout'
    TabOrder = 6
  end
end
