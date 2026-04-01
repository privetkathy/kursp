object FormAdmin: TFormAdmin
  Left = 0
  Top = 0
  Caption = 'FormAdmin'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object StringGridAll: TStringGrid
    Left = 192
    Top = 48
    Width = 320
    Height = 120
    TabOrder = 0
  end
  object EditNewCountry: TEdit
    Left = 96
    Top = 216
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'EditNewCountry'
  end
  object EditNewPrice: TEdit
    Left = 336
    Top = 224
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'EditNewPrice'
  end
  object EditNewDays: TEdit
    Left = 80
    Top = 272
    Width = 121
    Height = 23
    TabOrder = 3
    Text = 'EditNewDays'
  end
  object EditNewHotel: TEdit
    Left = 360
    Top = 264
    Width = 121
    Height = 23
    TabOrder = 4
    Text = 'EditNewHotel'
  end
  object BtnAdd: TButton
    Left = 56
    Top = 368
    Width = 75
    Height = 25
    Caption = 'BtnAdd'
    TabOrder = 5
  end
  object BtnDelete: TButton
    Left = 264
    Top = 376
    Width = 75
    Height = 25
    Caption = 'BtnDelete'
    TabOrder = 6
  end
  object BtnLogout: TButton
    Left = 464
    Top = 368
    Width = 75
    Height = 25
    Caption = 'BtnLogout'
    TabOrder = 7
  end
end
