object FormLogin: TFormLogin
  Left = 0
  Top = 0
  Caption = 'FormLogin'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LblStatus: TLabel
    Left = 168
    Top = 304
    Width = 48
    Height = 15
    Caption = 'LblStatus'
  end
  object EditLogin: TEdit
    Left = 136
    Top = 112
    Width = 121
    Height = 23
    TabOrder = 0
    Text = 'EditLogin'
  end
  object EditPass: TEdit
    Left = 136
    Top = 176
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'EditPass'
  end
  object BtnLogin: TButton
    Left = 128
    Top = 224
    Width = 75
    Height = 25
    Caption = 'BtnLogin'
    TabOrder = 2
  end
end
