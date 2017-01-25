object FormMain: TFormMain
  Left = 317
  Top = 223
  Width = 252
  Height = 276
  Caption = #1054#1087#1080#1089#1072#1085#1080#1077' '#1087#1083#1086#1089#1082#1080#1093' '#1092#1080#1075#1091#1088
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object pic: TImage
    Left = 8
    Top = 8
    Width = 225
    Height = 201
  end
  object MainMenu1: TMainMenu
    Left = 152
    Top = 40
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N9: TMenuItem
        Action = ActionExit
      end
    end
    object N2: TMenuItem
      Caption = #1060#1080#1075#1091#1088#1072
      object Action11: TMenuItem
        Action = ActionCircle
        AutoCheck = True
      end
      object Action21: TMenuItem
        Action = ActionRect
        AutoCheck = True
      end
      object Action31: TMenuItem
        Action = ActionSquare
        AutoCheck = True
      end
    end
    object N3: TMenuItem
      Caption = #1044#1077#1081#1089#1090#1074#1080#1077
      object N8: TMenuItem
        Action = ActionDraw
      end
      object N7: TMenuItem
        Caption = '-'
      end
      object N4: TMenuItem
        Action = ActionChange
      end
      object N5: TMenuItem
        Action = ActionMove
      end
      object N6: TMenuItem
        Action = ActionRotate
      end
    end
  end
  object ActionList1: TActionList
    Left = 184
    Top = 40
    object ActionCircle: TAction
      Category = #1060#1080#1075#1091#1088#1072
      AutoCheck = True
      Caption = #1050#1088#1091#1075
      GroupIndex = 1
      OnExecute = ActionCircleExecute
    end
    object ActionRect: TAction
      Category = #1060#1080#1075#1091#1088#1072
      AutoCheck = True
      Caption = #1055#1088#1103#1084#1086#1091#1075#1086#1083#1100#1085#1080#1082
      GroupIndex = 1
      OnExecute = ActionRectExecute
    end
    object ActionSquare: TAction
      Category = #1060#1080#1075#1091#1088#1072
      AutoCheck = True
      Caption = #1050#1074#1072#1076#1088#1072#1090
      GroupIndex = 1
      OnExecute = ActionSquareExecute
    end
    object ActionExit: TAction
      Category = #1060#1072#1081#1083
      Caption = #1042#1099#1093#1086#1076
      OnExecute = ActionExitExecute
    end
    object ActionChange: TAction
      Category = #1044#1077#1081#1089#1090#1074#1080#1077
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      OnExecute = ActionChangeExecute
    end
    object ActionMove: TAction
      Category = #1044#1077#1081#1089#1090#1074#1080#1077
      Caption = #1055#1077#1088#1077#1084#1077#1089#1090#1080#1090#1100
      OnExecute = ActionMoveExecute
    end
    object ActionRotate: TAction
      Category = #1044#1077#1081#1089#1090#1074#1080#1077
      Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1100
      OnExecute = ActionRotateExecute
    end
    object ActionDraw: TAction
      Category = #1044#1077#1081#1089#1090#1074#1080#1077
      Caption = #1053#1072#1088#1080#1089#1086#1074#1072#1090#1100
      OnExecute = ActionDrawExecute
    end
  end
end
