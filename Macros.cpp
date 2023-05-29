//
void   __fastcall Expansion_SET( char *s ); // ���������� ������� �������������� (���������� SET)
void   __fastcall Expansion_1_2_Opd( char *s, int nOpd ); // ��������� ���������� � 1-2 ����������
void   __fastcall SelectInstrForMacrosExpans(); // ����� ���� ���������� ��� ���������� ��������������
double __fastcall pcExpression( char* Expression, double Value_1, double Value_2 ); // ��������� � ������� double
int    __fastcall testIndex(char* str, char chr ); // ���������� ����� �� 'chr' ��������
//
void   __fastcall handOpd_asValue( char* Opd, INT i ); // // ��������� ����-�������� � ���� ���������� (�� �������������)
void   __fastcall handRes_asValue( char *Result, INT i ); // ��������� ����-���������� � ���� ���������� (�� �������������)
void   __fastcall handOpd_asMassive_1D( char* Opd, INT i ); // // ��������� ����-�������� � ���� �������������
void   __fastcall handRes_asMassive_1D( char *Result, INT i ); // ��������� ����-���������� � ����� �������������
//
void   __fastcall replace_Str( char s[], const char sOld[], const char sNew[] ); // ������ cI �� sNew � ������ s
bool   __fastcall makeMassive_1D( char str[], INT i ); // ������� � ������������ (���������) ������� � 1D-�������������
bool   __fastcall makeMassive_2D( char str[], INT i ); // ...2D-�������������
void   __fastcall tf_printf( char* str ); // ����� ������ str �� ����� ��������� � ���� fptrOut (global)
//
#define _tf_printf(str) t_printf("%s",str);fprintf(fptrOut,"%s\n",str); // ������ ������ ������ str �� ����� ��������� � ���� fptr
// ����������� �� ����� ����������: "�����>0" � "������ ������ - �����" ��� "������=attrvar"
#define permissName(str) ( strlen(str)&&(isalpha(str[0])||str[0]==attrVar[0]) )
//
 bool Rule_TokenUse = false; // ������������ �������� Opd ����� ���� ( "%s:%d:%d", Opd,numbFor,i-1 ) 
//
// makeMassive_1D, makeMassive_2D - ���������� ("�����������") ������� � 1D- � 2D-�������������
// handOpd_asMassive_1D - ���������� ���� �������� ��� 1D-������ (�������������)
// handOpd_asValue  - -.-.-.- ��� ������� ����������
// handRes_asMassive_1D - ���������� ���� ���������� ��� 1D-������ (������������)
// handRes_asValue  - -.-.-.- ��� ������� ����������
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall tf_printf( char* str )
{ // ����� ������ str  �� ����� ��������� + � ���� fptrOut (global)
 t_printf( "%s", str );
 fprintf( fptrOut, "%s\n", str );
} // ----- ����� tf_printf -----------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall Process_Macros()
{ // ������ ���������� �� ����� FileNameSet, ���� �������� ��������, ����������
// ���� �������� � mBody (��� TStringList), �������� ���������� �������� � ������
// ����� ���� � ������ ������� (���������� ��������)
 char str[_1024]="\0", strSave[_1024]="\0"; // ������ ��� ���������� � ����������� ���������� + ���������� �������� ������
//
 flagMacroTitle = false ; // !!!!!! ������� (global) !!!!!
//
 if( !(fptrIn = fopen( FileNameSet, "r") ) ) // ���� fptrIn (global) ������� �� �������...
  return false;
//
 strcpy( FileNameSetPrP, ChangeFileExt(FileNameSet,ExtPrP).c_str() ); // ��� ����� ���������� ����� �������������
 if( !(fptrOut = fopen( FileNameSetPrP, "w") ) ) // ���� ���������� ����� ������������� fptrOut (global) ������� �� �������...
  return false;
//
////////////////////////////////////////////////////////////////////////////////
//
 for( INT i=0; i<max_Instruction; i++ ) // �� ������� ����������
  {
//
   if(fgets(str, sizeof(str), fptrIn) == NULL) // ������ ������ �� fptr
    break; // ���� ������ ���������, ������� fgets ���������� NULL
//
   strcpy( strSave, str ); // �������� �������� ������
//
   if(str[strlen(str)-1] == 10) // ���� � ����� ������ ����� ������ (10) � ����������)...
    str[strlen(str)-1] = ' ';   // ... �� ������� �� ������ !
//
// ----- ��� Tab � ������ str �������� �� ������� ------------------------------
   for( INT i=0; i<strlen(str); i++ ) // �� ���� �������� ������...
    if( str[i] == VK_TAB ) // ���� i-��� ������ ���� Tab (9/0x9)...
     str[i] = VK_SPACE; // �� �������� ��� �� ������ (32/0x20) !
//
   DSTA( str ); // ������ ������ str �� ���������� � ������������� Tabs �  ��������
//
   if( !strlen(str) || // ���� ����� ������ �������...
       str[0]==startComments[0] || // ��� ������ ���������� � ";"...
       str[0]==':' ) // ������ ������...
    goto cont;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
  i_env_BypassMacro = setjmp( env_BypassMacro ); // ���������� ����� ��������
  if( i_env_BypassMacro ) // �� ���� - ������, ���� ��� ������ !!!!!!!!!!!!!!!!!
   goto label_BypassMacro;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
   if( !makeMassive_1D( str, i ) ) // ���������� ������� � 1D-������������
//   makeMassive_2D( str, i ); // ...� 2D-������������
    continue; // ������ str � �������� ���� fptrOut ����������� �� �����
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
label_BypassMacro: // ���� ��������� �� longjmp --------------------------------
////////////////////////////////////////////////////////////////////////////////
cont: // ��� �������� ������ � ������������ ����������� � ���� FileNameSetPrP --
////////////////////////////////////////////////////////////////////////////////
// ----- ��������� ������ � �������� ���� FileNameSetPrP -----------------------
 fputs( strSave, fptrOut ); // ��������� ������ ��������� �����
//
 } // ����� ����� i �� ������� � ����� FileNameSets
////////////////////////////////////////////////////////////////////////////////
//
 fclose( fptrIn  ); // ��������� ��� �������� �����
 fclose( fptrOut );
//
 return 0; // �� Ok
//
} // --------- ����� Process_Macros --------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall makeMassive_1D( char str[], INT i )
{ // ������� � ������������ (���������) ������ � 1D-������������� --------------
// ��� �������� false ������ str � �������� ���� ����������� �� ����� ! --------
  if( !strncmp( str, "for[", 4 ) && // ���� � ������ str ��������� 'for[' (������ 4 �������) '�'
       sscanf( str, "for[%c]=%d,%d,%d{", &cI,&minI,&maxI,&dI ) == 4 ) // ��� 4 ���� ��������� ���������..!
  { // ������ if( !strncmp( str, "for[", 4 ) && ...
//
   if( !dI || // ������� �������� ��������� ���������� ����� (�������� �  ����������� ������� )
     (  maxI>=minI && dI<=0) || ( maxI<=minI && dI>=0) )
   {
    t_printf( "\n-M- ����������� �������� ��������� [%d,%d,%d] ���������� ����� '%c' -M-\n", minI,maxI,dI,cI );
    return false; // ������ str � �������� ���� fptrOut ����������� �� �����
   }
//
   numbFor ++ ; // ����� for[... � ������ ���������
   flagMacroTitle = true; // ����� ������ � ���������� 1D-�������
   mBody->Clear(); // �������� mBody ���� TStringList
   mBody->Add( str ); // ��������� ��������� 1D-�������
   mExpand->Clear(); // ��������� � ���������� ������ ���������� ������� !!!
   return false; // ������ str � �������� ���� fptrOut ����������� �� �����
  } // ����� if( !strncmp( str, "for[", 4 ) && ...
//
  if( flagMacroTitle && str[0] != '}' ) // ���� �� ���� "}" � ������ ����� flagMacroTitle=true
  {
   mBody->Add( str ); // ��������� � mBody ������ �������
   return false; // ������ str � �������� ���� fptrOut ����������� �� �����
  }
//
  if( flagMacroTitle && str[0] == '}' ) // ����� ��������� ������� � ������ ���������� "}"
  {
   flagMacroTitle = false; // � ������ ���������� "}"
   mBody->Add( str ); // ��������� � mBody ������ "}"
//   endN = i; // �������� ����� ������ � ��������� �������� �������
//
////////////////////////////////////////////////////////////////////////////////
   SelectInstrForMacrosExpans(); // ����� ���� ���������� ��� ���������� ��������������
////////////////////////////////////////////////////////////////////////////////
   tf_printf( Format("; \n; ������ ���������� �������: ��������� 'for[%s]=%d,%d,%d {'\n; for_Id: %d", // cI -> %s !!!
              OPENARRAY(TVarRec,(cI,int(minI),int(maxI),int(dI),int(numbFor)))).c_str() );
   for( int j=0; j<mBody->Count; j++ )
    tf_printf( Format("; %s", OPENARRAY(TVarRec, (mBody->Strings[j].c_str()) )).c_str() );
   for( int j=0; j<mExpand->Count; j++ ) // ���������� ���������� �� ������-�������
    tf_printf( Format("%s",  OPENARRAY(TVarRec, (mExpand->Strings[j].c_str()) )).c_str() );
   tf_printf( Format("; \n; ����� ���������� �������: ��������� 'for[%s]=%d,%d,%d {'\n;", // cI -> %s !!!
              OPENARRAY(TVarRec,(cI,int(minI),int(maxI),int(dI)))).c_str() );
////////////////////////////////////////////////////////////////////////////////
   return false; // ������ str � �������� ���� fptrOut ����������� �� �����
  }
//
} // ------ ����� makeMassive_1D -----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall replace_Str( char* s, const char* sOld, const char* sNew )
{ // ��� ��������� sOld (����� ��� � ������ ����������� ������� stdFunc) � s ���������� �� sNew
//
 string strTmp;
//
// ------ ������ stdFunc[] -----------------------------------------------------
 for( int i=0; i<sizeof(stdFunc)/sizeof(stdFunc[0]); i++ ) // �� ��������� ����������� ������� �������
 {
  strReplace( w, sizeof(w)-1, s, stdFunc[i], Format( replaceFmt,OPENARRAY(TVarRec,(i))).c_str() );
  strcpy( s, w );
 } // ����� for( int i=0; i<sizeof(stdFunc)/sizeof(stdFunc[0]); i++ )
//
 for( int ii=10; ii>=2; ii-- ) // �������� �� ������� ii ���������������� cI
  if( strstr( s, strTmp.assign(ii,cI).c_str() ) ) 
  {
   t_printf( "\n-M- � ������ [%s] ��� ���������� �������� ������������ (%d) ������ ������� '%c' -M-\n", s,ii,cI );
   longjmp( env_BypassMacro, 1 ); // ����������� ������� � ����� setjmp !!!!!!!
  }
//
 strReplace( w, sizeof(w)-1, s, sOld, sNew ); // ������ ������ sOld �� ������ sNew (������ cI �� X[0])
//
 strcpy( s, w ); // ��������� � ������������� ������ ---------------------------
//
// ------ �������������� stdFunc[] ---------------------------------------------
 for( int i=0; i<sizeof(stdFunc)/sizeof(stdFunc[0]); i++ ) // �� ��������� ����������� ������� �������
 {
   strReplace( w, sizeof(w)-1, s, Format( replaceFmt,OPENARRAY(TVarRec,(i))).c_str(), stdFunc[i] );
   strcpy( s, w );
 } // ����� for( int i=0; i<sizeof(stdFunc)/sizeof(stdFunc[0]); i++ )
//
} // ------ ����� replace_Str --------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
double __fastcall pcExpression( char* Expression, double Value_1, double Value_2 )
{ // ��������� � ���������� ��������� Expression �� ���� ���������� Value_1/Value_2
//
 try
 {
  parser.Compile( Expression ); // �������� ���������
  parser.Evaluate( Value_1, Value_2 ); // ����� ���������� �� ���������� X[0],X[1] etc
  return parser.GetResult(); // ���������� double !!!
 }
 catch(TError error)
 {
  if( flagAlarmParser ) // ������ �������������� (global)
  {
   MessageBeep( MB_OK ); // �������� ��������������...
   snprintf( str,sizeof(str), "������������: �������� �������� ���������\n\n[%s]" // str - global
                              "\n\n������: [%s] � ������� %d",
             Expression, error.error, error.pos );
   MessageBox(0, str, " ������ !", MB_OK);
//
   flagAlarmParser = false; // global..!
  } // � ������ �� ��������..!
//
 } // ����� catch( )
//
} // -------- ����� pcExpression -----------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int __fastcall testIndex(char* str, char chr )
{ // ���� � ������ str ����� ����� 'chr' ����������� � ���� �����, ������� ����� ������
//
 int count = 0;
//
 for( int i=0; i<strlen(str); i++ ) // �� ���� ������ str
  if( isalpha(str[i]) && str[i] !=chr ) // ���� ����� � �� 'chr'
   count++;
//
 return count;
//
} // ------ ����� testIndex ----------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall SelectInstrForMacrosExpans()
{ // ����� ���� ���������� ������� ��� ���������� ��������������
//
 char Set[4]; // ��� ��������� ����������
//
 for( int j=1; j<mBody->Count-1; j++ ) // ���� �� ������� ���������� ������� (����� ��������� � ���������)
 {
  strncpy( Set, mBody->Strings[j].c_str(), 3 ); // ��������� ��������� ���������� (3 ������ �������)
  strupr( Set ); // ��������� � ��������� ��� ������������ ���������
//
  if( !strcmp( Set, "SET") ) // ��� SET ..!
   Expansion_SET( mBody->Strings[j].c_str() ); // ��������� ������ �� ���������� SET
  else // ��� �� SET (1-2 �������� � ����������)
   Expansion_1_2_Opd( mBody->Strings[j].c_str(), Get_CountOperandsByInstruction( Set ) );
 }
//
} // --------- ����� SelectInstrForMacrosExpans --------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall handRes_asValue( char *Res, INT i )
{ // ������������ ���� ����������, ���� �� � ����� ������� ���������� ----------
  if( Get_CountOperandsByInstruction( SetName ) == 1 ) // 1 ������� � ����������
   sprintf( w, "%s %s, %s%c%d%c%d ;%s", SetName,Opd_1,Res, SymbDelim,numbFor,SymbDelim,i, Comm );
  else // 2 �������� � ����������
   sprintf( w, "%s %s, %s, %s%c%d%c%d ;%s", SetName,Opd_1,Opd_2,Res, SymbDelim,numbFor,SymbDelim,i, Comm );
//
} // ----- ����� handRes_asValue -----------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Expansion_SET( char *s )
{ // ��������� ������ �� ���������� SET , ��������� ���������� � mExpand (TStringList)
//
 int out;
 string strTmp;
//
 for( INT i=minI; i<=maxI; i+=dI ) // �� ����� ��������� ��������� ���������� �������
 {
////////////////////////////////////////////////////////////////////////////////
// ----- ��������� 1-� ������� SET'� -------------------------------------------
//
  Comm[0] = '\0'; // ���������...
//
  strcpy( str, s ); // ��������, ��� ��� ��������� strtok �������� ������ s �����������
  strcpy( SetName,      p = strtok( str,  " " ) ); // ���������
  strcpy( Opd_1,   DAS( p = strtok( NULL, "," ) ) ); // 1-� �������
  strcpy( Res,     DAS( p = strtok( NULL, ";" ) ) ); // ���������
//
  if( strchr(s,';') ) // ���� � ������ ���� ';'
   strcpy( Comm, &s[strchr(s,';')-s+1] ); // �������� � Comm ��, ������ ';'
//  strcpy( Comm,    DAS( p = strtok( NULL, ""  ) ) ); // �����������
//
  replace_Str( Opd_1, strTmp.assign(1,cI).c_str(),  "X[0]" ); // ������ cI �� X[0] �������� ����� ����������� �������
//
  sprintf( Opd_1, "%.*g", sizeof(Mem_Data[0].Addr)-1, pcExpression( w,(double)i,0.0 ) );
// ------ ������������ ���� Res (��������� ���������� ����������) --------------
////////////////////////////////////////////////////////////////////////////////
  if( !strchr(Res, '[') && !strchr(Res,']') ) // � Res ��� � '[' � ']' ---------
   handRes_asValue( Res, i ); // ������������ ���������, ���� �� ������� ����������
  else
   handRes_asMassive_1D( Res, i ); // ������������ ���������, ���� �� ������������
////////////////////////////////////////////////////////////////////////////////
 } // ����� �� i (�� ����� ����� ����������) ===================================
//
////////////////////////////////////////////////////////////////////////////////
// for( int i=0; i<mExpand->Count; i++ ) // �������� �����
//  t_printf( "#%d# %s", i+1, mExpand->Strings[i] );
////////////////////////////////////////////////////////////////////////////////
//
} // ---------- ����� Expansion_SET --------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall handRes_asMassive_1D( char *Res, INT i )
{ // ������������ ���� ����������, ���� �� � ����� 1D-������������� ------------
//
  string strTmp;
//
  strcpy( nameMass,  p = strtok( Res,  "[" ) ); // ������ �� '['
  strcpy( indexMass, p = strtok( NULL, "]" ) ); // ������ �� '[' �� ']'
////////////////////////////////////////////////////////////////////////////////
//
  if( !permissName(nameMass) )
  { // �������� �� ������������ ����� ������� (����� > 0 �������� � ��������� ������ �����)
   t_printf( err_01, Res );
   longjmp( env_BypassMacro, 1 ); // ����������� ������� � ����� setjmp !!!!!!!
  }
//
////////////////////////////////////////////////////////////////////////////////
  strReplace( w, sizeof(w)-1, indexMass, strTmp.assign(1,cI).c_str(), "X[0]" ); // ������ ������ cI �� X[0]
//
  if( Get_CountOperandsByInstruction( SetName ) == 1 ) // 1 ������� � ����������
   sprintf( w, "%s %s, %s[%d] ; %s", SetName, Opd_1, nameMass, // ��������� ���������� ���� ����������
                                     (INT)pcExpression( w, (double)i,0.0 ), Comm );
  else
   sprintf( w, "%s %s, %s, %s[%d] ; %s", SetName, Opd_1,Opd_2, nameMass, // ��������� ���������� ���� ����������
                                         (INT)pcExpression( w, (double)i,0.0 ), Comm );
//
  mExpand->Add( w ); // ������� ������� ������ ���������� ��� ����������
//
} // ----- ����� handRes_asMassive_1D ------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall Expansion_1_2_Opd( char *s, int nOpd )
{ // ��������� ������ �� ���������� c 1-2 ���������� , ��������� ���������� �
// mExpand (TStringList) ; nOpd - ����� ���������
 bool outCode = true; // ������� ���������� SET
 int out;
//
 for( INT i=minI; i<=maxI; i+=dI ) // �� ����� ��������� ��������� ���������� �������
 {
////////////////////////////////////////////////////////////////////////////////
// ----- ��������� �������� �� SET'� -------------------------------------------
//
  strcpy( str, s ); // ��������, ��� ��� ��������� strtok �������� ������ s �����������
//
  Opd_2[0] = Comm[0] = '\0'; // ���������...
//
  strcpy( SetName,      p = strtok( str,  " " ) ); // ���������
  strcpy( Opd_1,   DAS( p = strtok( NULL, "," ) ) ); // 1-� �������
  if( nOpd == 2 )
   strcpy( Opd_2,  DAS( p = strtok( NULL, "," ) ) ) ; // 2-� �������
  strcpy( Res,     DAS( p = strtok( NULL, ";" ) ) ); // ���������
//
  if( strchr(s,';') ) // ���� � ������ ���� ';'
   strcpy( Comm, &s[strchr(s,';')-s+1] ); // �������� � Comm ��, ������ ';'
//
// ------ ������������ ���� Opd_1 (������ ������� ����������) ------------------
////////////////////////////////////////////////////////////////////////////////
  if( !strchr(Opd_1, '[') && !strchr(Opd_1,']') ) // � Opd_1 ��� � '[' � ']' ---
   handOpd_asValue( Opd_1, i ); // ������������ ���������, ���� �� ������� ����������
  else
   handOpd_asMassive_1D( Opd_1, i ); // ������������ ���������, ���� �� 1D-������������
// ------ ������������ ���� Opd_2 (������ ������� ����������) ------------------
////////////////////////////////////////////////////////////////////////////////
  if( nOpd  == 2 ) // 2-� �������
   if( !strchr(Opd_2, '[') && !strchr(Opd_2,']') ) // � Opd_2 ��� � '[' � ']' ---
    handOpd_asValue( Opd_2, i ); // ������������ ���������, ���� �� ������� ����������
   else
    handOpd_asMassive_1D( Opd_2, i ); // ������������ ���������, ���� �� 1D-������������
////////////////////////////////////////////////////////////////////////////////
// ------ ������������ ���� Res (��������� ���������� ����������) --------------
////////////////////////////////////////////////////////////////////////////////
  if( !strchr(Res, '[') && !strchr(Res,']') ) // � Res ��� � '[' � ']' ---------
   handRes_asValue( Res, i ); // ������������ ���������, ���� �� ������� ����������
  else
   handRes_asMassive_1D( Res, i ); // ������������ ���������, ���� �� 1D-������������
////////////////////////////////////////////////////////////////////////////////
//
// ---- �������� ������� ������ ���������� �� ��������� ����� ------------------
  if( nOpd == 1 ) // 1 �������
   sprintf( str, "%s %s, %s ; %s", SetName, Opd_1, Res, Comm ); // ������� ��������������� ������ ����������
  else
   sprintf( str, "%s %s, %s, %s ; %s", SetName, Opd_1, Opd_2, Res, Comm );
////////////////////////////////////////////////////////////////////////////////
// mExpand->Add( str ); // ������� ������� ������ ���������� ��� ����������
//
 } // ����� for( INT i=minI; i<=maxI; i+=dI )
//
} // ---------- ����� Expansion_1_2_Opd ----------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall handOpd_asValue( char* Opd, INT i )
{ // ������������ ���� ����������, ���� �� � ����� ������� ����������
// ��������� (Opd_1 ��� Opd_2) ���������� �� �� �� ����� !
//
 if( Rule_TokenUse ) // ������������ ����� ��� ����� �������� Opd
 {
  sprintf( w, "%s:%d:%d", Opd,numbFor,i-1 ); // ��� ���������� + id for + i (�����)
  strcpy( Opd, w ); // ������ � ��� �� ���� ���������
 }
//
} // ---------- ����� handOpd_asValue ------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall handOpd_asMassive_1D( char* Opd, INT i )
{ // ������������ ���� ����������, ���� �� � ����� 1D-�������������
// ��������� (Opd_1 ��� Opd_2) ���������� �� �� �� ����� !
//
  string strTmp;
//
  strcpy( nameMass,  p = strtok( Opd,  "[" ) ); // ������ �� '['
  strcpy( indexMass, p = strtok( NULL, "]" ) ); // ������ �� '[' �� ']' (���������� ������)
////////////////////////////////////////////////////////////////////////////////
//
  if( !permissName(nameMass) )
  { // �������� �� ������������ ����� ������� (����� > 0 �������� � ��������� ������ �����)
   t_printf( err_01, Opd );
   longjmp( env_BypassMacro, 1 ); // ����������� ������� � ����� setjmp !!!!!!!
  }
//
////////////////////////////////////////////////////////////////////////////////
  strReplace( w, sizeof(w)-1, indexMass, strTmp.assign(1,cI).c_str(), "X[0]" ); // ������ ������ cI �� X[0]
//
  sprintf( Opd, "%s[%d]", nameMass, (INT)pcExpression( w, (double)i,0.0 ), Comm );
//
} // ---------- ����� handOpd_asMassive_1D -------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall makeMassive_2D( char str[], INT i )
{ // ������� � ������������ (���������) ������ � 2D-������������� --------------
//
  if( !strncmp( str, "for[", 4 ) && // ���� � ������ str ��������� 'for[' (������ 4 �������) '�'
       sscanf( str, "for[%c:%c]=%d,%d,%d:%d,%d,%d{", &cI,&minI,&maxI,&dI, // ��� 8 ����� ��������� ���������..!
                                                     &cJ,&minJ,&maxJ,&dJ ) == 8 )
  { // ������ if( !strncmp( str, "for[", 4 ) && ...
//
   if( !dI || // ������� �������� ��������� ���������� ����� I (�������� � ����������� ������� )
     (  maxI>=minI && dI<=0) || ( maxI<=minI && dI>=0) )
   {
    t_printf( "\n-M- ����������� �������� ��������� [%d,%d,%d] ���������� ����� '%c' -M-\n", minI,maxI,dI,cI );
    return false; // ������ str � �������� ���� fptrOut ����������� �� �����
   }
//
   if( !dJ || // ������� �������� ��������� ���������� ����� J (�������� � ����������� ������� )
     (  maxJ>=minJ && dJ<=0) || ( maxJ<=minJ && dJ>=0) )
   {
    t_printf( "\n-M- ����������� �������� ��������� [%d,%d,%d] ���������� ����� '%c' -M-\n", minJ,maxJ,dJ,cJ );
    return false;  // ������ str � �������� ���� fptrOut ����������� �� �����
   }
//
   if( cI == cJ ) // ���������� ������� ����� ������
   {
    t_printf( "\n-M- ���������� ������� ��������� ������ - �������: '%c' , ����������: '%c' -M-\n", cI, cJ );
    return false;  // ������ str � �������� ���� fptrOut ����������� �� �����
   }
//
   numbFor ++ ; // ����� for[... � ������ ���������
   flagMacroTitle = true; // ����� ������ � ���������� 1D-�������
   mBody->Clear(); // �������� mBody ���� TStringList
   mBody->Add( str ); // ��������� ��������� 1D-�������
   mExpand->Clear(); // ��������� � ���������� ������ ���������� ������� !!!
   return false;  // ������ str � �������� ���� fptrOut ����������� �� �����
  } // ����� if( !strncmp( str, "for[", 4 ) && ...
//
  if( flagMacroTitle && str[0] != '}' ) // ���� �� ���� "}" � ������ ����� flagMacroTitle=true
  {
   mBody->Add( str ); // ��������� � mBody ������ �������
   return false; // ������ str � �������� ���� fptrOut ����������� �� �����
  }
//
  if( flagMacroTitle && str[0] == '}' ) // ����� ��������� ������� � ������ ���������� "}"
  {
   flagMacroTitle = false; // � ������ ���������� "}"
   mBody->Add( str ); // ��������� � mBody ������ "}"
//
////////////////////////////////////////////////////////////////////////////////
//   SelectInstrForMacrosExpans(); // ����� ���� ���������� ��� ���������� ��������������
////////////////////////////////////////////////////////////////////////////////
   tf_printf( Format("; \n; ������ ���������� �������: ��������� 'for[%s]=%d,%d,%d {'\n; for_Id: %d", // cI -> %s !!!
              OPENARRAY(TVarRec,(cI,int(minI),int(maxI),int(dI),int(numbFor)))).c_str() );
   for( int j=0; j<mBody->Count; j++ )
    tf_printf( Format("; %s", OPENARRAY(TVarRec, (mBody->Strings[j].c_str()) )).c_str() );
   for( int j=0; j<mExpand->Count; j++ ) // ���������� ���������� �� ������-�������
    tf_printf( Format("%s",  OPENARRAY(TVarRec, (mExpand->Strings[j].c_str()) )).c_str() );
   tf_printf( Format("; \n; ����� ���������� �������: ��������� 'for[%s]=%d,%d,%d {'\n;", // cI -> %s !!!
              OPENARRAY(TVarRec,(cI,int(minI),int(maxI),int(dI)))).c_str() );
////////////////////////////////////////////////////////////////////////////////
    return false;  // ������ str � �������� ���� fptrOut ����������� �� �����
  }
//
} // ------ ����� makeMassive_2D -----------------------------------------------


