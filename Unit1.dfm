object F1: TF1
  Left = 374
  Top = 297
  Width = 1145
  Height = 622
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  ActiveControl = BitBtn_Run
  BorderIcons = [biSystemMenu, biMinimize]
  BorderWidth = 1
  Caption =
    '��������� ����������� ����������� DATA-FLOW (2009-2020) ver.4.4.' +
    '2; ����� 2020'
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'System'
  Font.Style = [fsBold]
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000FFFFFFFFF
    FF000000000000000000000FFFFFFFFFFFFFFFFFF000000000FFFFFFFFFFFFFF
    FFFFF0000000FFF0000FFFFFFFFFFFFFFFF0000000000FFF0000FFFFFFFFFFFF
    FFF333333333FFFFF00000FFFFFFFFFFFFF33AAAAA33FFFFFF0000FFFFFFFFFF
    FFF3AAAAAAA3FFFFFFF0000FFFFFFFFFFFF3AAAAAAA3FFFFFFFF000FFFFFFFFF
    FFF3AAAAAAA3FFFFFFFF0000FFFFFFFFFFF33AAAAA33FFFFFFFFF000FFFFFFFF
    FFF333333333FFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFF
    FFFFFFFFFF000FFFFFFFF0000FFFFFFFFFFFFFFFFF000FF0FFFFF0000FFFFFFF
    FFFFFFFFFF000F000FFF0000FFFFFFFFFFFFFFFFF0000000FFFF0000FFFFFFFF
    FFFFFFFFF000000FFFF0000FFFFFFFFFFFFFFFFFF00000FFFF0000FFFFFFFFFF
    FFFFFFFF0000000FF0000FFFFFFFFFFFFFFFFFF00000EE000000FFFFFFFFFFFF
    FFFFFF000F00EEE0000FFFFFFFFFFFFFFFFFFFF0FFF00EEE00FFFFFFFFFFFFFF
    FFFFFFFFFFFF00EEE00FFFFFFFFFFFFFFFFFFFFFFFFFF00EEE00FFFFFFFFFFFF
    FFFFFFFFFFFFFF00EEE00FFFFFFFFFFFFFFFFFFFFFFFFFF00EEE00FFFFFFFFFF
    FFFFFFFFFFFFFFFF00EEE00FFFFFFFFFFFFFFFFFFFFFFFFFF00E000FFFFFFFFF
    FFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  KeyPreview = True
  Menu = Main_Menu
  OldCreateOrder = False
  Position = poScreenCenter
  ShowHint = True
  OnClose = F1_OnClose
  OnKeyUp = F1_OnKeyUp
  OnResize = F1_OnResize
  OnShow = F1_OnShow
  DesignSize = (
    1127
    561)
  PixelsPerInch = 96
  TextHeight = 16
  object Label_Data: TLabel
    Left = 948
    Top = 185
    Width = 54
    Height = 16
    Hint = '����������� ������ (������������� ������ ������)'
    Alignment = taRightJustify
    Anchors = [akLeft, akTop, akRight]
    Caption = '������'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object Label_Set: TLabel
    Left = 747
    Top = 185
    Width = 62
    Height = 16
    Hint = '����������� ���������'
    Alignment = taRightJustify
    Caption = '�������'
    Color = clBtnFace
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    WordWrap = True
  end
  object TLabel
    Left = 144
    Top = 1
    Width = 4
    Height = 16
    Alignment = taCenter
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clPurple
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_Buffer: TLabel
    Left = 102
    Top = 184
    Width = 100
    Height = 16
    Hint = '����� ���-��������'
    Alignment = taRightJustify
    Caption = '����� ������'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object Label1: TLabel
    Left = 352
    Top = 181
    Width = 4
    Height = 16
  end
  object Label_AIU: TLabel
    Left = 434
    Top = 181
    Width = 70
    Height = 16
    Hint =
      '����� �������������� ����������� ��������� (���, ������������  �' +
      '����������)'
    Caption = '����� ���'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object StatusBarMain: TStatusBar
    Left = 0
    Top = 542
    Width = 1127
    Height = 19
    Hint = '���������� � ��������� ������� � ����������� ��������'
    Panels = <
      item
        Width = 380
      end
      item
        Width = 350
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object SG_Data: TStringGrid
    Left = 810
    Top = 207
    Width = 190
    Height = 308
    Hint = '������ (�������� - ����� ������ ����, ���������� Alt+F2)'
    TabStop = False
    ColCount = 2
    DefaultColWidth = 98
    DefaultRowHeight = 19
    FixedColor = 14671616
    FixedCols = 0
    RowCount = 2
    TabOrder = 6
    OnMouseDown = SG_Data_Info
    OnTopLeftChanged = SG_Data_TopLeftChanged
  end
  object SG_Set: TStringGrid
    Left = 235
    Top = 207
    Width = 557
    Height = 308
    Hint = 
      '�������� (�������� ����������) � �� �������� (�������� ������'#13#10'�' +
      '�� ���������� ��������); ������ ������ ������ ���� - �����������' +
      #13#10'�������������� ������ ����� ���������� � ������������'
    TabStop = False
    ColCount = 8
    DefaultColWidth = 90
    DefaultRowHeight = 19
    FixedColor = 8585090
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
    PopupMenu = SG_PopUpMenu
    TabOrder = 5
    OnDblClick = SG_Sets_Edit
    OnDrawCell = SG_Sets_DrawCell
    OnSelectCell = SG_SetSelectCell
    RowHeights = (
      19
      19)
  end
  object M1: TMemo
    Left = 4
    Top = -2
    Width = 999
    Height = 166
    Hint = 
      '�������� ������ ����������� ( I - ����������, E - ������, W - ��' +
      '������������ )'
    PopupMenu = M1_PopUpMenu
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object BitBtn_Run: TBitBtn
    Left = 3
    Top = 175
    Width = 102
    Height = 26
    Hint = '������ c����'
    Caption = '����������'
    TabOrder = 1
    OnClick = Run_Calculations
  end
  object BitBtn_Stop: TBitBtn
    Left = 222
    Top = 175
    Width = 124
    Height = 26
    Hint = '������� ����� (Ctrl+S)'
    Caption = '������� / �����'
    TabOrder = 2
    OnClick = Stop_Calculations
  end
  object SG_Buffer: TStringGrid
    Left = 4
    Top = 207
    Width = 197
    Height = 308
    Hint = '����� ������ (��������� � 1)'
    TabStop = False
    ColCount = 2
    DefaultColWidth = 100
    DefaultRowHeight = 19
    FixedColor = 10790143
    FixedCols = 0
    RowCount = 2
    TabOrder = 3
    OnTopLeftChanged = SG_Buffer_TopLeftChanged
  end
  object PB_1: TProgressBar
    Left = 206
    Top = 207
    Width = 17
    Height = 308
    Cursor = crCross
    Hint = '������� ������������� ������ ����������'
    Min = 0
    Max = 100
    Orientation = pbVertical
    ParentShowHint = False
    Step = 1
    ShowHint = True
    TabOrder = 4
  end
  object E_AIU: TEdit
    Left = 368
    Top = 175
    Width = 73
    Height = 24
    Hint = 
      '����� ��� (�������������� �������������� ��������� '#13#10'- ���������' +
      '� ������������ ������������)'
    AutoSize = False
    MaxLength = 7
    TabOrder = 8
    OnKeyPress = OnKeyPress_E_AIU
  end
  object Main_Menu: TMainMenu
    Left = 155
    Top = 40
    object Files: TMenuItem
      Caption = '�����'
      HelpContext = 1000
      Hint = '������ � �������'
      ShortCut = 32881
      object N1: TMenuItem
        Caption = '������� � ��������� ���������'
        HelpContext = 1001
        Hint = '������� � ��������� ���� ��������� (SET-����)'
        ShortCut = 114
        OnClick = Load_Sets
      end
      object N18: TMenuItem
        Caption = '-'
      end
      object N17: TMenuItem
        Caption = '���������� �����'
        ShortCut = 116
        OnClick = Rewrite_Files
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object N15: TMenuItem
        Caption = '��������� ��� ��������� '
        ShortCut = 113
        OnClick = Save_All_Protocols
      end
      object N36: TMenuItem
        Caption = '��������� ������'
        ShortCut = 32881
        OnClick = Save_Data
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object N16: TMenuItem
        Caption = '��������� �������������'
        ShortCut = 32856
        OnClick = On_Close_Main_Form
      end
    end
    object Work: TMenuItem
      Caption = '������'
      object N3: TMenuItem
        Caption = '����������'
        ShortCut = 120
        OnClick = Run_Calculations
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object N7: TMenuItem
        Caption = '���������� ����'
        ShortCut = 32858
        OnClick = Stop_Calculations
      end
      object N8: TMenuItem
        Caption = '-'
      end
      object N9: TMenuItem
        Caption = '���������� ����������'
        OnClick = Mixed_Sets
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object SaveIGA: TMenuItem
        Caption = '��������� ��������� � ����� ���'
        Hint = '��������� ��������� � ���� ��������������� ���� ��������� (���)'
        ShortCut = 118
        OnClick = Save_IGA_Click
      end
      object ExtendedSave_IGA: TMenuItem
        Caption = '���������� ��� ���'
        ShortCut = 16502
        OnClick = ExtendedSave_IGA_Click
      end
      object N28: TMenuItem
        Caption = '-'
      end
      object N30: TMenuItem
        Caption = '������ ������������� ����������'
        ShortCut = 117
        OnClick = Show_Graph
      end
      object N10: TMenuItem
        Caption = '������ �������� ���'
        ShortCut = 16501
        OnClick = Show_AIU
      end
    end
    object Edit: TMenuItem
      Caption = '��������������'
      object N24: TMenuItem
        Caption = '������������� ���� ����������'
        ShortCut = 16499
        OnClick = SG_Sets_Edit
      end
      object N25: TMenuItem
        Caption = '-'
      end
      object N22: TMenuItem
        Caption = '������������� ���� ��������'
        ShortCut = 8307
        OnClick = INI_Edit
      end
    end
    object Info: TMenuItem
      Caption = '�������������� ���������'
      object N14: TMenuItem
        Caption = '����� �����������'
        ShortCut = 112
        OnClick = Show_Chema
      end
      object N12: TMenuItem
        Caption = '�������� ����������'
        ShortCut = 32880
        OnClick = N12Click
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object N26: TMenuItem
        Caption = '�� ����������� DATA-FLOW'
        Hint = '������� �������� ������'
        OnClick = About_AW
      end
      object SPFhome: TMenuItem
        Caption = '����������������� ������ SPF@home'
        Hint = '������� �������� ������'
        OnClick = About_SPF
      end
      object N23: TMenuItem
        Caption = '������������ ������������ �� ����'
        Hint = '������� �������� ������'
        OnClick = About_Poems
      end
      object N20: TMenuItem
        Caption = '-'
      end
      object Rar1: TMenuItem
        Caption = '�������� ����� ������ ���������'
        Hint = '�������� � ���������� In!Data'
        OnClick = OnClickGetRar
      end
      object N21: TMenuItem
        Caption = '���������� ��������'
        ShortCut = 16449
        OnClick = EndedUploadFile
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object Info_AW: TMenuItem
        Caption = 'WEB-������ AlgoWiki'
        Hint = '������� �� ���� AlgoWiki'
        OnClick = About_AW
      end
    end
    object N27: TMenuItem
      OnClick = Most_Wonderful
    end
    object Wonderful: TMenuItem
      Caption = '����� ������������...'
      OnClick = Most_Wonderful
    end
    object TMenuItem
    end
    object Analize: TMenuItem
      Caption = '������/�������'
      Hint = '�������������� ����������� �������'
      object N31: TMenuItem
        Caption = '��������������� ����������'
        Hint = '��������������� ������������� �� ������ ������ ����������'
        ShortCut = 121
        OnClick = DrawNotExecuteSets
      end
      object N32: TMenuItem
        Caption = '-'
      end
      object N33: TMenuItem
        Caption = '���������������� ����������'
        Hint = 
          '��������������� ����������, ���������� ���������� ������� ����� ' +
          '�� ������������'
        ShortCut = 122
        OnClick = DrawNotUsedResults
      end
      object N34: TMenuItem
        Caption = '-'
      end
      object N35: TMenuItem
        Caption = '�������������� ��������'
        Hint = '��������, �������� ������� �� ����������'
        ShortCut = 123
        OnClick = DrawNotDetermineOperands
      end
    end
    object N37: TMenuItem
      Caption = '�������� �������'
      Hint = 
        '�������� ������������� ����� ������� ���������� � ������� ������' +
        '������� ����������'
      object SelectColors_Test: TMenuItem
        Caption = '����� �������'
        Hint = 
          '����� ���� ����� ������� ���������� � ������ ������� (����������' +
          '��)'
        object clOperandOperation: TMenuItem
          Tag = 11
          Caption = '����� ��������� � ��������'
          Hint = '������������ ����� ��������� � ��������'
          OnClick = SelectColors
        end
        object clNonExecuted: TMenuItem
          Tag = 12
          Caption = '��������������� ��������'
          Hint = '������ ���������� ��������������� ��������'
          OnClick = SelectColors
        end
        object clNonUsedResult: TMenuItem
          Tag = 13
          Caption = '���������������� ���������� ��������'
          Hint = 
            '������ �������� ���������� ��������, �� �������������� � �������' +
            '� ���������'
          OnClick = SelectColors
        end
        object clNonDefOperands: TMenuItem
          Tag = 14
          Caption = '������������� ��������'
          Hint = '�������� ��������, �������� ������� �� ������'
          OnClick = SelectColors
        end
      end
      object N39: TMenuItem
        Caption = '-'
      end
      object SelecColors_Execute: TMenuItem
        Caption = '����� ����������'
        Hint = 
          '����� ���� ����� ������� ���������� � ������ ���������� ��������' +
          '�'
        object clReadyOperand: TMenuItem
          Tag = 21
          Caption = '���������� ���������'
          OnClick = SelectColors
        end
        object clTruePredictor: TMenuItem
          Tag = 22
          Caption = '���������� ����� ����������'
          Hint = '��� ������� ������ ���� ��e������� ���������� � TRUE'
          OnClick = SelectColors
        end
        object clExecInstruction: TMenuItem
          Tag = 23
          Caption = '������� ���������� ����������'
          Hint = '��� ��������� ������ ���������� ���������'
          OnClick = SelectColors
        end
      end
      object N38: TMenuItem
        Caption = '-'
      end
      object SelectColor_Graph: TMenuItem
        Caption = '������ ������������� ����������'
        Hint = '����� ������� ������������� ����������'
        object N40: TMenuItem
          Tag = 31
          Caption = '������ ���� �������'
          OnClick = SelectColors
        end
        object N41: TMenuItem
          Tag = 32
          Caption = '����� ���� �������'
          OnClick = SelectColors
        end
      end
    end
  end
  object OD_1: TOpenDialog
    DefaultExt = 'set'
    Filter = '����� ���������|*.set|��� �����|*.*'
    Left = 315
    Top = 29
  end
  object SG_PopUpMenu: TPopupMenu
    OnPopup = OnPopup_Determine_Links
    Left = 626
    Top = 347
    object RO_1: TMenuItem
      Caption = '��������� -> ��������'
      OnClick = Result_toOperands
    end
    object N29: TMenuItem
      Caption = '-'
    end
    object OR_1: TMenuItem
      Caption = '������� -> ���������'
      OnClick = Operand_toResult
    end
  end
  object Master_Timer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = On_Master_Timer
    Left = 410
    Top = 70
  end
  object INC0: TIdHTTP
    OnStatus = INC0_OnStatus
    OnDisconnected = INC0_Disconnected
    OnWork = INC0_OnWork
    OnWorkBegin = INC0_OnWorkBegin
    OnWorkEnd = INC0_OnWorkEnd
    OnConnected = INC0_Connected
    Request.Accept = 'text/html, */*'
    Request.ContentLength = 0
    Request.ContentRangeEnd = 0
    Request.ContentRangeStart = 0
    Request.ProxyPort = 0
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Left = 264
    Top = 64
  end
  object CD_1: TColorDialog
    Ctl3D = True
    OnShow = CD_1_Show
    Options = [cdFullOpen, cdAnyColor]
    Left = 496
    Top = 80
  end
  object M1_PopUpMenu: TPopupMenu
    Left = 616
    Top = 80
    object N42: TMenuItem
      Caption = '�������� ��'
      OnClick = M1_ClearAll
    end
    object N43: TMenuItem
      Caption = '-'
    end
    object ClipBoard1: TMenuItem
      Caption = '���������� �� � ClipBoard'
      OnClick = M1_CopyAll
    end
    object NotePad1: TMenuItem
      Caption = '������� ���������� � NotePad'
      OnClick = M1_CopyToNotepad
    end
  end
end
