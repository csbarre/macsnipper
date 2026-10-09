/* ST-MAC | 2026-10-09 | Ghidra C-like pseudocode. Not original or buildable C++. */

/* Function 180001000 FUN_180001000 */

void FUN_180001000(void)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  undefined1 auStack_58 [32];
  void *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_58;
  local_30 = 0xcff52e04;
  local_2c = 0x4614cca6;
  local_28 = 0x49757ea1;
  local_24 = 0x994ac810;
  local_38 = (void *)0x0;
  lVar2 = GetActivationFactoryByPCWSTR(L"Windows.UI.Colors",(Guid *)&local_30,&local_38);
  if (lVar2 < 0) {
    FUN_180001ad4(lVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  local_20[0] = 0;
  iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_38,local_20);
  if (-1 < iVar3) {
    if (local_38 != (void *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    FUN_18000c7f0(local_18 ^ (ulonglong)auStack_58);
    return;
  }
  FUN_180001ad4(iVar3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800010b0 FUN_1800010b0 */

void FUN_1800010b0(void)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [32];
  undefined1 local_38 [24];
  longlong local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_58;
  iVar2 = WindowsCreateStringReference(L".png",4,local_38,&local_20);
  if (iVar2 < 0) {
    FUN_180001ad4(iVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  uVar3 = 0;
  if ((local_20 != 0) &&
     (iVar2 = WindowsDuplicateString(local_20,&local_18), uVar3 = local_18, iVar2 < 0)) {
    FUN_180001ad4(iVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_18001f650 = uVar3;
  atexit(FUN_180015920);
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_58);
  return;
}


/* Function 180001140 FUN_180001140 */

void FUN_180001140(void)

{
  atexit(FUN_180015990);
  return;
}


/* Function 180001150 FUN_180001150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180001150(void)

{
  InitOnceExecuteOnce((PINIT_ONCE)&DAT_18001ef10,FUN_18000c3e0,(PVOID)0x0,(LPVOID *)0x0);
  DAT_18001ef28 = 1;
  _DAT_18001eef0 = &DAT_18001ef18;
  return;
}


/* Function 180001190 FUN_180001190 */

void FUN_180001190(void)

{
  atexit(std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t);
  return;
}


/* Function 1800011a0 FUN_1800011a0 */

wchar_t * FUN_1800011a0(wchar_t *param_1,void *param_2,size_t param_3,undefined4 param_4)

{
  void *_Dst;
  longlong *plVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  
  param_1[0] = L'\0';
  param_1[1] = L'\0';
  param_1[2] = L'\0';
  param_1[3] = L'\0';
  param_1[8] = L'\0';
  param_1[9] = L'\0';
  param_1[10] = L'\0';
  param_1[0xb] = L'\0';
  param_1[0xc] = L'\a';
  param_1[0xd] = L'\0';
  param_1[0xe] = L'\0';
  param_1[0xf] = L'\0';
  *param_1 = L'\0';
  pwVar4 = param_1 + 0x10;
  pwVar4[0] = L'\0';
  pwVar4[1] = L'\0';
  pwVar4[2] = L'\0';
  pwVar4[3] = L'\0';
  param_1[0x18] = L'\0';
  param_1[0x19] = L'\0';
  param_1[0x1a] = L'\0';
  param_1[0x1b] = L'\0';
  param_1[0x1c] = L'\a';
  param_1[0x1d] = L'\0';
  param_1[0x1e] = L'\0';
  param_1[0x1f] = L'\0';
  *pwVar4 = L'\0';
  *(undefined4 *)(param_1 + 0x20) = param_4;
  uVar2 = 0xffffffffffffffff;
  do {
    uVar2 = uVar2 + 1;
  } while (*(short *)((longlong)param_2 + uVar2 * 2) != 0);
  if (*(ulonglong *)(param_1 + 0xc) < uVar2) {
    FUN_1800014a8((longlong *)param_1,uVar2,param_3,param_2);
  }
  else {
    pwVar3 = param_1;
    if (7 < *(ulonglong *)(param_1 + 0xc)) {
      pwVar3 = *(wchar_t **)param_1;
    }
    *(ulonglong *)(param_1 + 8) = uVar2;
    param_3 = uVar2 * 2;
    memmove(pwVar3,param_2,param_3);
    pwVar3[uVar2] = L'\0';
  }
  if (*(ulonglong *)(param_1 + 0x1c) < 0x3f) {
    FUN_1800014a8((longlong *)pwVar4,0x3f,param_3,
                  L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp");
  }
  else {
    _Dst = *(void **)pwVar4;
    param_1[0x18] = L'?';
    param_1[0x19] = L'\0';
    param_1[0x1a] = L'\0';
    param_1[0x1b] = L'\0';
    memmove(_Dst,L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0x7e);
    *(undefined2 *)((longlong)_Dst + 0x7e) = 0;
  }
  plVar1 = (longlong *)FUN_180001e7c();
  if (7 < *(ulonglong *)(param_1 + 0x1c)) {
    pwVar4 = *(wchar_t **)pwVar4;
  }
  pwVar3 = param_1;
  if (7 < *(ulonglong *)(param_1 + 0xc)) {
    pwVar3 = *(wchar_t **)param_1;
  }
  FUN_1800021bc(plVar1,pwVar3,pwVar4,*(int *)(param_1 + 0x20),L"Start");
  return param_1;
}


/* Function 1800012bc FUN_1800012bc */

void FUN_1800012bc(wchar_t *param_1)

{
  wchar_t *pwVar1;
  longlong *plVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  
  plVar2 = (longlong *)FUN_180001e7c();
  pwVar1 = param_1 + 0x10;
  pwVar4 = pwVar1;
  if (7 < *(ulonglong *)(param_1 + 0x1c)) {
    pwVar4 = *(wchar_t **)pwVar1;
  }
  pwVar3 = param_1;
  if (7 < *(ulonglong *)(param_1 + 0xc)) {
    pwVar3 = *(wchar_t **)param_1;
  }
  FUN_1800021bc(plVar2,pwVar3,pwVar4,*(int *)(param_1 + 0x20),L"End");
  FUN_1800015f0((longlong *)pwVar1);
  FUN_1800015f0((longlong *)param_1);
  return;
}


/* Function 180001320 FUN_180001320 */

void FUN_180001320(void)

{
  code *pcVar1;
  
  std::_Xlength_error("string too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180001334 FUN_180001334 */

undefined8 * FUN_180001334(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}


/* Function 180001370 FUN_180001370 */

undefined8 * FUN_180001370(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 1800013b4 FUN_1800013b4 */

undefined8 * FUN_1800013b4(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}


/* Function 1800013f4 FUN_1800013f4 */

undefined8 * FUN_1800013f4(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}


/* Function 180001440 FUN_180001440 */

char * FUN_180001440(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(longlong *)(param_1 + 8) != 0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}


/* Function 180001454 FUN_180001454 */

undefined8 * FUN_180001454(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  return param_1;
}


/* Function 180001488 FUN_180001488 */

void FUN_180001488(void)

{
  undefined8 local_28 [5];
  
  FUN_180001334(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001a768);
}


/* Function 1800014a8 FUN_1800014a8 */

longlong * FUN_1800014a8(longlong *param_1,ulonglong param_2,undefined8 param_3,void *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  code *pcVar3;
  void *pvVar4;
  longlong *plVar5;
  ulonglong uVar6;
  void *_Memory;
  ulonglong uVar7;
  void *_Dst;
  
  uVar7 = 0x7ffffffffffffffe;
  if (0x7ffffffffffffffe < param_2) {
    FUN_180001320();
    pcVar3 = (code *)swi(3);
    plVar5 = (longlong *)(*pcVar3)();
    return plVar5;
  }
  uVar2 = param_1[3];
  uVar6 = param_2 | 7;
  if ((uVar6 < 0x7fffffffffffffff) && (uVar2 <= 0x7ffffffffffffffe - (uVar2 >> 1))) {
    uVar1 = (uVar2 >> 1) + uVar2;
    uVar7 = uVar6;
    if (uVar6 < uVar1) {
      uVar7 = uVar1;
    }
    if (0x7fffffffffffffff < uVar7 + 1) goto LAB_1800015e7;
    uVar6 = (uVar7 + 1) * 2;
    if (0xfff < uVar6) goto LAB_18000152e;
    _Dst = (void *)0x0;
    if (uVar6 != 0) {
      _Dst = operator_new(uVar6);
    }
  }
  else {
    uVar6 = 0xfffffffffffffffe;
LAB_18000152e:
    if (uVar6 + 0x27 <= uVar6) {
LAB_1800015e7:
      FUN_180001488();
      pcVar3 = (code *)swi(3);
      plVar5 = (longlong *)(*pcVar3)();
      return plVar5;
    }
    pvVar4 = operator_new(uVar6 + 0x27);
    if (pvVar4 == (void *)0x0) goto LAB_1800015da;
    _Dst = (void *)((longlong)pvVar4 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)_Dst - 8) = pvVar4;
  }
  param_1[3] = uVar7;
  param_1[2] = param_2;
  memcpy(_Dst,param_4,param_2 * 2);
  *(undefined2 *)(param_2 * 2 + (longlong)_Dst) = 0;
  if (7 < uVar2) {
    pvVar4 = (void *)*param_1;
    _Memory = pvVar4;
    if ((0xfff < uVar2 * 2 + 2) &&
       (_Memory = *(void **)((longlong)pvVar4 + -8),
       0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)_Memory)))) {
LAB_1800015da:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  *param_1 = (longlong)_Dst;
  return param_1;
}


/* Function 1800015f0 FUN_1800015f0 */

void FUN_1800015f0(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}


/* Function 180001654 FUN_180001654 */

void FUN_180001654(longlong *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,param_2,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800016dc FUN_1800016dc */

void FUN_1800016dc(longlong *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  undefined1 local_18 [8];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,param_2,local_18);
  if (-1 < iVar2) {
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180001724 FUN_180001724 */

void FUN_180001724(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_48 [56];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_48;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  if (-1 < iVar2) {
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_48);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 18000176c FUN_18000176c */

void FUN_18000176c(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800017f4 FUN_1800017f4 */

void FUN_1800017f4(longlong *param_1)

{
  int *piVar1;
  ControlBlock *pCVar2;
  int iVar3;
  longlong lVar4;
  ControlBlock *this;
  
  if ((param_1[1] != 0) && (param_1[1] != -1)) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    param_1[1] = 0;
  }
  if (DAT_18001eee0 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  lVar4 = *param_1;
  LOCK();
  piVar1 = (int *)(lVar4 + 0xc);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    *(undefined4 *)(lVar4 + 0xc) = 0xc0000000;
  }
  this = (ControlBlock *)*param_1;
  Platform::Details::ControlBlock::ReleaseTarget(this);
  LOCK();
  pCVar2 = this + 8;
  iVar3 = *(int *)pCVar2;
  *(int *)pCVar2 = *(int *)pCVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    if (this[0x19] != (ControlBlock)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180001880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      Platform::Details::Heap::AlignedFree(this);
      return;
    }
    Platform::Details::Heap::Free(this);
  }
  return;
}


/* Function 180001894 FUN_180001894 */

void FUN_180001894(longlong param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  undefined1 local_18 [8];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  if ((param_1 != 0) && (iVar2 = WindowsDuplicateString(param_1,local_18), iVar2 < 0)) {
    FUN_180001ad4(iVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
  return;
}


/* Function 1800018e0 Decrement */

/* Library Function - Single Match
    public: unsigned long __cdecl __abi_FTMWeakRefData::Decrement(void)volatile __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ulong __thiscall __abi_FTMWeakRefData::Decrement(__abi_FTMWeakRefData *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulong uVar4;
  
  if ((*(longlong *)this == 0) || (*(int *)(*(longlong *)this + 0xc) < 0)) {
    uVar4 = 0xffffffff;
  }
  else {
    lVar3 = *(longlong *)this;
    LOCK();
    piVar1 = (int *)(lVar3 + 0xc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    uVar4 = iVar2 - 1;
    if (uVar4 == 0) {
      *(undefined4 *)(lVar3 + 0xc) = 0xc0000000;
      if ((*(longlong *)(this + 8) != 0) && (*(longlong *)(this + 8) != -1)) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)();
        *(undefined8 *)(this + 8) = 0;
      }
      if (DAT_18001eee0 != 0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)();
      }
    }
  }
  return uVar4;
}


/* Function 180001970 FUN_180001970 */

void FUN_180001970(longlong *param_1,int *param_2,undefined8 param_3)

{
  code *pcVar1;
  HRESULT HVar2;
  bool bVar3;
  undefined1 auStack_48 [32];
  LPUNKNOWN local_28;
  ulonglong local_20;
  
  local_20 = DAT_18001e100 ^ (ulonglong)auStack_48;
  if ((((param_1[1] != 0) && (*param_2 == 3)) && (param_2[1] == DAT_180016abc)) &&
     ((param_2[2] == DAT_180016ac0 && (param_2[3] == DAT_180016ac4)))) {
    if (param_1[1] == -1) {
      HVar2 = CoCreateFreeThreadedMarshaler(*(LPUNKNOWN *)(*param_1 + 0x10),&local_28);
      if (HVar2 < 0) {
        FUN_180001ad4(HVar2);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      LOCK();
      bVar3 = param_1[1] == -1;
      if (bVar3) {
        param_1[1] = (longlong)local_28;
      }
      UNLOCK();
      if (!bVar3) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)();
      }
    }
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1[1],param_2,param_3);
  }
  FUN_18000c7f0(local_20 ^ (ulonglong)auStack_48);
  return;
}


/* Function 180001a40 FUN_180001a40 */

undefined8 FUN_180001a40(void)

{
  return 0;
}


/* Function 180001a44 FUN_180001a44 */

void FUN_180001a44(longlong param_1)

{
  WindowsDeleteString(*(undefined8 *)(param_1 + 0x18));
  return;
}


/* Function 180001a50 FUN_180001a50 */

void * FUN_180001a50(void *param_1,wchar_t *param_2)

{
  code *pcVar1;
  int iVar2;
  size_t sVar3;
  void *pvVar4;
  
  sVar3 = wcslen(param_2);
  if ((param_2 == (wchar_t *)0x0) || (sVar3 == 0)) {
    memset(param_1,0,0x20);
  }
  else {
    if (0xffffffff < sVar3) {
      __abi_WinRTraiseInvalidArgumentException();
      pcVar1 = (code *)swi(3);
      pvVar4 = (void *)(*pcVar1)();
      return pvVar4;
    }
    iVar2 = WindowsCreateStringReference
                      (param_2,sVar3 & 0xffffffff,param_1,(longlong)param_1 + 0x18);
    if (iVar2 < 0) {
      FUN_180001ad4(iVar2);
      pcVar1 = (code *)swi(3);
      pvVar4 = (void *)(*pcVar1)();
      return pvVar4;
    }
  }
  return param_1;
}


/* Function 180001ac0 FUN_180001ac0 */

undefined8 FUN_180001ac0(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


/* Function 180001ac8 WindowsDeleteString */

void WindowsDeleteString(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d438. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsDeleteString();
  return;
}


/* Function 180001ad0 _guard_check_icall */

void _guard_check_icall(void)

{
  return;
}


/* Function 180001ad4 FUN_180001ad4 */

void FUN_180001ad4(int param_1)

{
  code *pcVar1;
  
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      __abi_WinRTraiseFailureException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7ffffff5) {
      __abi_WinRTraiseOutOfBoundsException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7ffffff4) {
      __abi_WinRTraiseChangedStateException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7fffffed) {
      __abi_WinRTraiseObjectDisposedException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7fffbfff) {
      __abi_WinRTraiseNotImplementedException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7fffbffe) {
      __abi_WinRTraiseInvalidCastException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7fffbffd) {
      __abi_WinRTraiseNullReferenceException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7fffbffc) {
      __abi_WinRTraiseOperationCanceledException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    if (param_1 == -0x7ffefef8) {
      __abi_WinRTraiseDisconnectedException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7ffefef2) {
      __abi_WinRTraiseWrongThreadException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7ffbfeac) {
      __abi_WinRTraiseClassNotRegisteredException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7ff8fffb) {
      __abi_WinRTraiseAccessDeniedException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7ff8fff2) {
      __abi_WinRTraiseOutOfMemoryException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1 == -0x7ff8ffa9) {
      __abi_WinRTraiseInvalidArgumentException();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  __abi_WinRTraiseCOMException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180001bb4 FUN_180001bb4 */

void FUN_180001bb4(char param_1,undefined8 *param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  if (((param_2 != (undefined8 *)0x0) &&
      (iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_2,param_3,&local_18),
      param_1 == '\0')) && (iVar2 < 0)) {
    FUN_180001ad4(iVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
  return;
}


/* Function 180001c34 FUN_180001c34 */

void FUN_180001c34(longlong *param_1)

{
  if (param_1 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return;
}


/* Function 180001c50 FUN_180001c50 */

longlong * FUN_180001c50(longlong *param_1)

{
  if (param_1 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return param_1;
}


/* Function 180001c74 FUN_180001c74 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_180001c74(longlong param_1)

{
  wchar_t *pwVar1;
  longlong local_res8;
  undefined4 *local_res10;
  undefined4 *local_res18;
  undefined *local_res20;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined4 **local_90;
  undefined1 **local_88;
  undefined1 *local_80;
  longlong *local_78;
  undefined1 **local_70;
  undefined1 local_68 [8];
  undefined1 local_60 [24];
  undefined1 local_48 [8];
  undefined1 local_40 [32];
  
  local_res20 = &DAT_18001f618;
  local_98 = (undefined1 *)0x558cf1724f30aa6d;
  local_90 = (undefined4 **)0x57eda441ba2e7773;
  local_b8 = 0x4f50731a;
  local_b4 = 0x478289cf;
  local_b0 = 0xe8dce0b3;
  local_ac = 0xba7604c9;
  local_res10 = &local_b8;
  local_res8 = param_1;
  FUN_180004e64(&local_res8,&local_res10);
  pwVar1 = L"Microsoft.ScreenSketch";
  WindowsCreateStringReference(L"Microsoft.ScreenSketch",0x16,local_60,local_68);
  local_80 = local_68;
  local_78 = &local_res8;
  local_70 = &local_98;
  FUN_1800055ac(pwVar1,(undefined8 *)&DAT_18001f618,&local_80);
  if (local_res8 != 0) {
    FUN_180005034(&local_res8);
  }
  local_80 = (undefined1 *)0x462c2655ef00584a;
  local_78 = (longlong *)0xbf7f0e63dee724bc;
  local_a8 = 0x4f50731a;
  local_a4 = 0x478289cf;
  local_a0 = 0xe8dce0b3;
  local_9c = 0xba7604c9;
  local_res18 = &local_a8;
  FUN_180004e64(&local_res10,&local_res18);
  pwVar1 = L"Microsoft.Windows.AppLifeCycle";
  WindowsCreateStringReference(L"Microsoft.Windows.AppLifeCycle",0x1e,local_40,local_48);
  local_98 = local_48;
  local_90 = &local_res10;
  local_88 = &local_80;
  FUN_1800055ac(pwVar1,(undefined8 *)&DAT_18001f620,&local_98);
  if (local_res10 != (undefined4 *)0x0) {
    FUN_180005034(&local_res10);
  }
  _DAT_18001f628 = 0;
  uRam000000018001f630 = 0;
  _DAT_18001f638 = 0;
  uRam000000018001f640 = 0;
  _DAT_18001f648 = 0;
  return &DAT_18001f618;
}


/* Function 180001e04 FUN_180001e04 */

void FUN_180001e04(longlong *param_1)

{
  if (param_1[6] != 0) {
    FUN_180005034(param_1 + 6);
  }
  if (param_1[5] != 0) {
    FUN_180005034(param_1 + 5);
  }
  if (param_1[4] != 0) {
    FUN_180005034(param_1 + 4);
  }
  if (param_1[3] != 0) {
    FUN_180005034(param_1 + 3);
  }
  if (param_1[2] != 0) {
    FUN_180005034(param_1 + 2);
  }
  if (param_1[1] != 0) {
    FUN_180005034(param_1 + 1);
  }
  if (*param_1 != 0) {
    FUN_180005034(param_1);
  }
  return;
}


/* Function 180001e7c FUN_180001e7c */

undefined * FUN_180001e7c(void)

{
  undefined4 *puVar1;
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <
      DAT_18001f610) {
    puVar1 = &DAT_18001f610;
    _Init_thread_header(&DAT_18001f610);
    if (DAT_18001f610 == -1) {
      FUN_180001c74((longlong)puVar1);
      atexit(FUN_180015910);
      _Init_thread_footer(&DAT_18001f610);
    }
  }
  return &DAT_18001f618;
}


/* Function 180001ee4 FUN_180001ee4 */

void FUN_180001ee4(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  undefined1 local_18 [8];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,local_18);
  if (-1 < iVar2) {
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180001f30 FUN_180001f30 */

void FUN_180001f30(longlong *param_1,undefined8 *param_2,longlong *param_3)

{
  int iVar1;
  undefined1 auStackY_98 [32];
  undefined8 *local_68;
  longlong local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  longlong *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStackY_98;
  local_30 = 0x200000000000;
  local_68 = &local_30;
  local_38 = param_3;
  FUN_180004c18(&local_60,&local_68);
  local_68 = (undefined8 *)((ulonglong)local_68 & 0xffffffff00000000);
  iVar1 = WindowsCreateStringReference(*param_2,*(undefined4 *)(param_2 + 1),local_50,&local_58);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  FUN_180002000(param_1,&local_58,param_3,(undefined4 *)&local_68,&local_60);
  if (local_60 != 0) {
    FUN_180005034(&local_60);
  }
  if (*param_3 != 0) {
    FUN_180005034(param_3);
  }
  FUN_18000c7f0(local_28 ^ (ulonglong)auStackY_98);
  return;
}


/* Function 180002000 FUN_180002000 */

void FUN_180002000(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4,
                  undefined8 *param_5)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  longlong local_48;
  longlong local_40;
  ulonglong local_38;
  
  local_38 = DAT_18001e100 ^ (ulonglong)auStack_78;
  local_48 = *param_1;
  if (local_48 != 0) {
    local_40 = 0;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_48,&DAT_180016ca0,&local_40);
    local_48 = local_40;
  }
  local_58 = *param_5;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_48,*param_2,*param_3,*param_4);
  if (-1 < iVar2) {
    FUN_180005034(&local_48);
    FUN_18000c7f0(local_38 ^ (ulonglong)auStack_78);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800020a8 FUN_1800020a8 */

void FUN_1800020a8(longlong *param_1)

{
  if (*param_1 != 0) {
    FUN_180005034(param_1);
  }
  return;
}


/* Function 1800020bc FUN_1800020bc */

void FUN_1800020bc(longlong *param_1,undefined8 *param_2,longlong *param_3)

{
  int iVar1;
  undefined1 auStackY_98 [32];
  undefined8 *local_68;
  longlong local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  longlong *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStackY_98;
  local_30 = 0x400000000000;
  local_68 = &local_30;
  local_38 = param_3;
  FUN_180004c18(&local_60,&local_68);
  local_68 = (undefined8 *)((ulonglong)local_68 & 0xffffffff00000000);
  iVar1 = WindowsCreateStringReference(*param_2,*(undefined4 *)(param_2 + 1),local_50,&local_58);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  FUN_180002000(param_1,&local_58,param_3,(undefined4 *)&local_68,&local_60);
  if (local_60 != 0) {
    FUN_180005034(&local_60);
  }
  if (*param_3 != 0) {
    FUN_180005034(param_3);
  }
  FUN_18000c7f0(local_28 ^ (ulonglong)auStackY_98);
  return;
}


/* Function 18000218c FUN_18000218c */

void FUN_18000218c(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,*param_2,*param_3);
  if (-1 < iVar2) {
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800021bc FUN_1800021bc */

void FUN_1800021bc(longlong *param_1,wchar_t *param_2,wchar_t *param_3,int param_4,wchar_t *param_5)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auStack_1b8 [32];
  longlong local_198;
  longlong local_190;
  wchar_t *local_188;
  undefined8 auStack_180 [3];
  longlong local_168;
  undefined1 local_160 [20];
  int iStack_14c;
  longlong local_148;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> local_140 [8];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_138 [120];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_c0 [104];
  ulonglong local_58;
  
  local_58 = DAT_18001e100 ^ (ulonglong)auStack_1b8;
  lVar6 = 0xe8;
  memset(&local_148,0,0xe8);
  FUN_180003b30((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_148);
  pbVar4 = FUN_180003ef0((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_148,
                         param_2);
  pbVar4 = FUN_180003ef0(pbVar4,L"\r\n  ");
  pbVar4 = FUN_180003ef0(pbVar4,param_3);
  pbVar4 = FUN_180003ef0(pbVar4,L"(");
  pbVar4 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(pbVar4,param_4)
  ;
  pbVar4 = FUN_180003ef0(pbVar4,L")");
  pbVar4 = FUN_180003ef0(pbVar4,L"\r\n  ");
  FUN_180003ef0(pbVar4,param_5);
  FUN_180003df4((longlong)local_140,&local_168,lVar6);
  FUN_1800015f0(&local_168);
  cVar2 = FUN_180001ee4(param_1);
  if (cVar2 != '\0') {
    FUN_180004a2c(&local_198);
    lVar5 = -1;
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (param_2[lVar6] != L'\0');
    WindowsCreateStringReference(param_2,lVar6,auStack_180,&local_188);
    WindowsCreateStringReference(L"FunctionName",0xc,local_160,&local_168);
    FUN_18000218c(&local_198,&local_168,&local_188);
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (param_3[lVar6] != L'\0');
    WindowsCreateStringReference(param_3,lVar6,local_160,&local_168);
    WindowsCreateStringReference(L"File",4,auStack_180,&local_188);
    FUN_18000218c(&local_198,&local_188,&local_168);
    WindowsCreateStringReference(L"Line",4,local_160,&local_168);
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_198,local_168,(longlong)param_4);
    if (iVar3 < 0) {
      FUN_18000533c(iVar3);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    do {
      lVar5 = lVar5 + 1;
    } while (param_5[lVar5] != L'\0');
    WindowsCreateStringReference(param_5,lVar5,local_160,&local_168);
    WindowsCreateStringReference(L"CustomMessage",0xd,auStack_180,&local_188);
    FUN_18000218c(&local_198,&local_188,&local_168);
    local_190 = local_198;
    if (local_198 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_198);
    }
    local_188 = L"Information";
    auStack_180[0] = 0xb;
    FUN_180001f30(param_1,&local_188,&local_190);
    if (local_198 != 0) {
      FUN_180005034(&local_198);
    }
  }
  *(undefined ***)(local_140 + (longlong)*(int *)(local_148 + 4) + -8) = &PTR_FUN_18001e138;
  *(int *)((longlong)&iStack_14c + (longlong)*(int *)(local_148 + 4)) =
       *(int *)(local_148 + 4) + -0x88;
  FUN_180003a68(local_140);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>(local_138);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_c0);
  FUN_18000c7f0(local_58 ^ (ulonglong)auStack_1b8);
  return;
}


/* Function 1800024b4 FUN_1800024b4 */

void FUN_1800024b4(longlong *param_1)

{
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  
  this = (basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 0x11);
  *(undefined ***)(this + (longlong)*(int *)(*param_1 + 4) + -0x88) = &PTR_FUN_18001e138;
  *(int *)(this + (longlong)*(int *)(*param_1 + 4) + -0x8c) = *(int *)(*param_1 + 4) + -0x88;
  FUN_180003a68((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 1));
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 2));
                    /* WARNING: Could not recover jumptable at 0x000180002510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  return;
}


/* Function 180002518 FUN_180002518 */

void FUN_180002518(longlong *param_1,undefined8 param_2,undefined8 param_3,int param_4,
                  Message *param_5,wchar_t *param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar5;
  String *pSVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStack_1a8 [32];
  String *local_188;
  String *local_180;
  longlong local_178;
  undefined1 local_170 [24];
  wchar_t *local_158;
  undefined8 auStack_150 [2];
  int iStack_13c;
  longlong local_138;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> local_130 [8];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_128 [120];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_b0 [104];
  ulonglong local_48;
  
  local_48 = DAT_18001e100 ^ (ulonglong)auStack_1a8;
  lVar10 = 0xe8;
  memset(&local_138,0,0xe8);
  FUN_180003b30((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_138);
  pbVar5 = FUN_180003ef0((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_138,
                         L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync"
                        );
  pbVar5 = FUN_180003ef0(pbVar5,L"\r\n  ");
  pbVar5 = FUN_180003ef0(pbVar5,
                         L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp");
  pbVar5 = FUN_180003ef0(pbVar5,L"(");
  pbVar5 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(pbVar5,param_4)
  ;
  pbVar5 = FUN_180003ef0(pbVar5,L")");
  pbVar5 = FUN_180003ef0(pbVar5,L"\r\n  ");
  pbVar5 = FUN_180003ef0(pbVar5,param_6);
  pbVar5 = FUN_180003ef0(pbVar5,L"\r\n  ");
  pSVar6 = Platform::Exception::Message::get(param_5);
  local_180 = pSVar6;
  pwVar7 = (wchar_t *)WindowsGetStringRawBuffer(pSVar6,0);
  FUN_180003ef0(pbVar5,pwVar7);
  WindowsDeleteString(pSVar6);
  FUN_180003df4((longlong)local_130,&local_178,lVar10);
  FUN_1800015f0(&local_178);
  cVar3 = FUN_180001ee4(param_1);
  if (cVar3 != '\0') {
    FUN_180004a2c(&local_188);
    WindowsCreateStringReference
              (L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",0x4b,
               auStack_150,&local_158);
    WindowsCreateStringReference(L"FunctionName",0xc,local_170,&local_178);
    FUN_18000218c(&local_188,&local_178,&local_158);
    WindowsCreateStringReference
              (L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0x3f,
               local_170,&local_178);
    WindowsCreateStringReference(L"File",4,auStack_150,&local_158);
    FUN_18000218c(&local_188,&local_158,&local_178);
    WindowsCreateStringReference(L"Line",4,local_170,&local_178);
    pSVar6 = local_188;
    iVar4 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_188,local_178,(longlong)param_4);
    if (iVar4 < 0) {
      FUN_18000533c(iVar4);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar1 = *(undefined4 *)(param_5 + 0x40);
    WindowsCreateStringReference(L"HRESULT",7,local_170,&local_178);
    iVar4 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(pSVar6,local_178,uVar1);
    if (iVar4 < 0) {
      FUN_18000533c(iVar4);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    pSVar6 = Platform::Exception::Message::get(param_5);
    local_180 = pSVar6;
    lVar10 = WindowsGetStringRawBuffer(pSVar6,0);
    lVar9 = -1;
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (*(short *)(lVar10 + lVar8 * 2) != 0);
    WindowsCreateStringReference(lVar10,lVar8,local_170,&local_178);
    WindowsCreateStringReference(L"ExceptionMessage",0x10,auStack_150,&local_158);
    FUN_18000218c(&local_188,&local_158,&local_178);
    WindowsDeleteString(pSVar6);
    do {
      lVar9 = lVar9 + 1;
    } while (param_6[lVar9] != L'\0');
    WindowsCreateStringReference(param_6,lVar9,local_170,&local_178);
    WindowsCreateStringReference(L"CustomMessage",0xd,auStack_150,&local_158);
    FUN_18000218c(&local_188,&local_158,&local_178);
    local_180 = local_188;
    if (local_188 != (String *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_188);
    }
    local_158 = L"Exception";
    auStack_150[0] = 9;
    FUN_1800020bc(param_1,&local_158,(longlong *)&local_180);
    if (local_188 != (String *)0x0) {
      FUN_180005034(&local_188);
    }
  }
  *(undefined ***)(local_130 + (longlong)*(int *)(local_138 + 4) + -8) = &PTR_FUN_18001e138;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(local_138 + 4)) =
       *(int *)(local_138 + 4) + -0x88;
  FUN_180003a68(local_130);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>(local_128);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_b0);
  FUN_18000c7f0(local_48 ^ (ulonglong)auStack_1a8);
  return;
}


/* Function 180002910 FUN_180002910 */

void FUN_180002910(longlong *param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  char *pcVar5;
  wchar_t ****ppppwVar6;
  longlong lVar7;
  undefined8 in_stack_00000028;
  undefined1 auStack_2a8 [32];
  ulonglong local_288;
  ulonglong local_280;
  wchar_t ***local_278;
  undefined8 uStack_270;
  undefined4 local_268;
  ulonglong local_260;
  undefined8 local_258;
  undefined1 local_250 [24];
  longlong local_238;
  undefined1 local_230 [20];
  int iStack_21c;
  undefined *local_218 [2];
  undefined *local_208;
  undefined **local_200;
  basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> local_1f8 [96];
  undefined8 local_198;
  undefined4 local_190;
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_180 [100];
  int iStack_11c;
  longlong local_118;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> local_110 [8];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_108 [120];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_90 [104];
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStack_2a8;
  local_280 = local_280 & 0xffffffff00000000;
  lVar7 = 0xe8;
  memset(&local_118,0,0xe8);
  FUN_180003b30((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_118);
  pbVar4 = FUN_180003ef0((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_118,
                         L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync"
                        );
  pbVar4 = FUN_180003ef0(pbVar4,L"\r\n  ");
  pbVar4 = FUN_180003ef0(pbVar4,
                         L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp");
  pbVar4 = FUN_180003ef0(pbVar4,L"(");
  pbVar4 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(pbVar4,0xfc);
  pbVar4 = FUN_180003ef0(pbVar4,L")");
  pbVar4 = FUN_180003ef0(pbVar4,L"\r\n  ");
  pbVar4 = FUN_180003ef0(pbVar4,L"Responding to toast display request failed");
  pbVar4 = FUN_180003ef0(pbVar4,L"\r\n  ");
  pcVar5 = (char *)(*(code *)PTR__guard_dispatch_icall_1800165a8)(in_stack_00000028);
  FUN_18000407c(pbVar4,pcVar5);
  FUN_180003df4((longlong)local_110,&local_238,lVar7);
  FUN_1800015f0(&local_238);
  cVar2 = FUN_180001ee4(param_1);
  if (cVar2 != '\0') {
    FUN_180004a2c(&local_288);
    WindowsCreateStringReference
              (L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",0x4b,
               &uStack_270,&local_278);
    WindowsCreateStringReference(L"FunctionName",0xc,local_250,&local_258);
    FUN_18000218c(&local_288,&local_258,&local_278);
    WindowsCreateStringReference
              (L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0x3f,
               local_250,&local_258);
    WindowsCreateStringReference(L"File",4,&uStack_270,&local_278);
    FUN_18000218c(&local_288,&local_278,&local_258);
    WindowsCreateStringReference(L"Line",4,local_250,&local_258);
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_288,local_258,0xfc);
    if (iVar3 < 0) {
      FUN_18000533c(iVar3);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    memset(local_218,0,0xf8);
    local_218[0] = &DAT_180016cc8;
    local_208 = &DAT_180016cc0;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_180);
    local_280 = CONCAT44(local_280._4_4_,3);
    lVar7 = 0;
    std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)local_218,
               (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_200);
    *(undefined ***)((longlong)local_218 + (longlong)*(int *)(local_218[0] + 4)) =
         &PTR_FUN_18001e1b8;
    *(int *)((longlong)&iStack_21c + (longlong)*(int *)(local_218[0] + 4)) =
         *(int *)(local_218[0] + 4) + -0x98;
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_200);
    local_200 = &PTR_FUN_18001e140;
    local_198 = 0;
    local_190 = 0;
    pcVar5 = (char *)(*(code *)PTR__guard_dispatch_icall_1800165a8)(in_stack_00000028);
    FUN_18000407c((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_208,pcVar5);
    FUN_180003df4((longlong)&local_200,(longlong *)&local_278,lVar7);
    ppppwVar6 = &local_278;
    if (7 < local_260) {
      ppppwVar6 = (wchar_t ****)local_278;
    }
    WindowsCreateStringReference(ppppwVar6,local_268,local_250,&local_258);
    WindowsCreateStringReference(L"ExceptionMessage",0x10,local_230,&local_238);
    FUN_18000218c(&local_288,&local_238,&local_258);
    FUN_1800015f0((longlong *)&local_278);
    WindowsCreateStringReference
              (L"Responding to toast display request failed",0x2a,local_230,&local_238);
    WindowsCreateStringReference(L"CustomMessage",0xd,local_250,&local_258);
    FUN_18000218c(&local_288,&local_258,&local_238);
    local_280 = local_288;
    if (local_288 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_288);
    }
    local_278 = (wchar_t ***)0x180016c58;
    uStack_270 = 0xc;
    FUN_1800020bc(param_1,&local_278,(longlong *)&local_280);
    *(undefined ***)((longlong)local_218 + (longlong)*(int *)(local_218[0] + 4)) =
         &PTR_FUN_18001e1b8;
    *(int *)((longlong)&iStack_21c + (longlong)*(int *)(local_218[0] + 4)) =
         *(int *)(local_218[0] + 4) + -0x98;
    FUN_180003a68((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_200);
    std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>(local_1f8);
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_180);
    if (local_288 != 0) {
      FUN_180005034(&local_288);
    }
  }
  *(undefined ***)(local_110 + (longlong)*(int *)(local_118 + 4) + -8) = &PTR_FUN_18001e138;
  *(int *)((longlong)&iStack_11c + (longlong)*(int *)(local_118 + 4)) =
       *(int *)(local_118 + 4) + -0x88;
  FUN_180003a68(local_110);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>(local_108);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_90);
  FUN_18000c7f0(local_28 ^ (ulonglong)auStack_2a8);
  return;
}


/* Function 180002da0 FUN_180002da0 */

void FUN_180002da0(longlong *param_1)

{
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  
  this = (basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 0x13);
  *(undefined ***)(this + (longlong)*(int *)(*param_1 + 4) + -0x98) = &PTR_FUN_18001e1b8;
  *(int *)(this + (longlong)*(int *)(*param_1 + 4) + -0x9c) = *(int *)(*param_1 + 4) + -0x98;
  FUN_180003a68((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 3));
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 4));
                    /* WARNING: Could not recover jumptable at 0x000180002dfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  return;
}


/* Function 180002e04 FUN_180002e04 */

void FUN_180002e04(longlong *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar5;
  undefined8 *puVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  longlong in_stack_00000028;
  undefined1 auStack_178 [32];
  longlong local_158;
  longlong local_150;
  longlong local_148;
  undefined1 local_140 [24];
  wchar_t *local_128;
  undefined8 auStack_120 [2];
  int iStack_10c;
  longlong local_108;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> local_100 [8];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_f8 [120];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_80 [104];
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_178;
  lVar8 = 0xe8;
  memset(&local_108,0,0xe8);
  FUN_180003b30((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_108);
  pbVar5 = FUN_180003ef0((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_108,
                         L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync"
                        );
  pbVar5 = FUN_180003ef0(pbVar5,L"\r\n  ");
  pbVar5 = FUN_180003ef0(pbVar5,
                         L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp");
  pbVar5 = FUN_180003ef0(pbVar5,L"(");
  pbVar5 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(pbVar5,0xfc);
  pbVar5 = FUN_180003ef0(pbVar5,L")");
  pbVar5 = FUN_180003ef0(pbVar5,L"\r\n  ");
  pbVar5 = FUN_180003ef0(pbVar5,L"Responding to toast display request failed");
  pbVar5 = FUN_180003ef0(pbVar5,L"\r\n  HRESULT: ");
  pbVar5 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                     (pbVar5,*(int *)(in_stack_00000028 + 0xc));
  pbVar5 = FUN_180003ef0(pbVar5,L"\r\n  ");
  puVar6 = (undefined8 *)FUN_1800046f4(in_stack_00000028,&local_150);
  pwVar7 = (wchar_t *)WindowsGetStringRawBuffer(*puVar6,0);
  FUN_180003ef0(pbVar5,pwVar7);
  if (local_150 != 0) {
    WindowsDeleteString();
  }
  FUN_180003df4((longlong)local_100,&local_148,lVar8);
  FUN_1800015f0(&local_148);
  cVar3 = FUN_180001ee4(param_1);
  if (cVar3 != '\0') {
    FUN_180004a2c(&local_158);
    WindowsCreateStringReference
              (L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",0x4b,
               auStack_120,&local_128);
    WindowsCreateStringReference(L"FunctionName",0xc,local_140,&local_148);
    FUN_18000218c(&local_158,&local_148,&local_128);
    WindowsCreateStringReference
              (L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0x3f,
               local_140,&local_148);
    WindowsCreateStringReference(L"File",4,auStack_120,&local_128);
    FUN_18000218c(&local_158,&local_128,&local_148);
    WindowsCreateStringReference(L"Line",4,local_140,&local_148);
    iVar4 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_158,local_148,0xfc);
    if (iVar4 < 0) {
      FUN_18000533c(iVar4);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar6 = (undefined8 *)FUN_1800046f4(in_stack_00000028,&local_150);
    local_128 = (wchar_t *)*puVar6;
    WindowsCreateStringReference(L"ExceptionMessage",0x10,local_140,&local_148);
    FUN_18000218c(&local_158,&local_148,&local_128);
    if (local_150 != 0) {
      WindowsDeleteString();
    }
    uVar1 = *(undefined4 *)(in_stack_00000028 + 0xc);
    WindowsCreateStringReference(L"HRESULT",7,local_140,&local_148);
    iVar4 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_158,local_148,uVar1);
    if (iVar4 < 0) {
      FUN_18000533c(iVar4);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    WindowsCreateStringReference
              (L"Responding to toast display request failed",0x2a,local_140,&local_148);
    WindowsCreateStringReference(L"CustomMessage",0xd,auStack_120,&local_128);
    FUN_18000218c(&local_158,&local_128,&local_148);
    local_150 = local_158;
    if (local_158 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_158);
    }
    local_128 = L"StdException";
    auStack_120[0] = 0xc;
    FUN_1800020bc(param_1,&local_128,&local_150);
    if (local_158 != 0) {
      FUN_180005034(&local_158);
    }
  }
  *(undefined ***)(local_100 + (longlong)*(int *)(local_108 + 4) + -8) = &PTR_FUN_18001e138;
  *(int *)((longlong)&iStack_10c + (longlong)*(int *)(local_108 + 4)) =
       *(int *)(local_108 + 4) + -0x88;
  FUN_180003a68(local_100);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>(local_f8);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_80);
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_178);
  return;
}


/* Function 1800031f0 FUN_1800031f0 */

void FUN_1800031f0(longlong *param_1,undefined8 param_2,undefined8 param_3,int param_4,
                  wchar_t *param_5)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  longlong lVar5;
  undefined1 auStack_188 [32];
  longlong local_168;
  longlong local_160;
  wchar_t *local_158;
  undefined8 auStack_150 [3];
  longlong local_138;
  undefined1 local_130 [20];
  int iStack_11c;
  longlong local_118;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> local_110 [8];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_108 [120];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_90 [104];
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStack_188;
  lVar5 = 0xe8;
  memset(&local_118,0,0xe8);
  FUN_180003b30((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_118);
  pbVar4 = FUN_180003ef0((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&local_118,
                         L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync"
                        );
  pbVar4 = FUN_180003ef0(pbVar4,L"\r\n  ");
  pbVar4 = FUN_180003ef0(pbVar4,
                         L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp");
  pbVar4 = FUN_180003ef0(pbVar4,L"(");
  pbVar4 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(pbVar4,param_4)
  ;
  pbVar4 = FUN_180003ef0(pbVar4,L")");
  pbVar4 = FUN_180003ef0(pbVar4,L"\r\n  ");
  FUN_180003ef0(pbVar4,param_5);
  FUN_180003df4((longlong)local_110,&local_138,lVar5);
  FUN_1800015f0(&local_138);
  cVar2 = FUN_180001ee4(param_1);
  if (cVar2 != '\0') {
    FUN_180004a2c(&local_168);
    WindowsCreateStringReference
              (L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",0x4b,
               auStack_150,&local_158);
    WindowsCreateStringReference(L"FunctionName",0xc,local_130,&local_138);
    FUN_18000218c(&local_168,&local_138,&local_158);
    WindowsCreateStringReference
              (L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0x3f,
               local_130,&local_138);
    WindowsCreateStringReference(L"File",4,auStack_150,&local_158);
    FUN_18000218c(&local_168,&local_158,&local_138);
    WindowsCreateStringReference(L"Line",4,local_130,&local_138);
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_168,local_138,(longlong)param_4);
    if (iVar3 < 0) {
      FUN_18000533c(iVar3);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (param_5[lVar5] != L'\0');
    WindowsCreateStringReference(param_5,lVar5,local_130,&local_138);
    WindowsCreateStringReference(L"ExceptionMessage",0x10,auStack_150,&local_158);
    FUN_18000218c(&local_168,&local_158,&local_138);
    local_160 = local_168;
    if (local_168 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_168);
    }
    local_158 = L"UnknownException";
    auStack_150[0] = 0x10;
    FUN_1800020bc(param_1,&local_158,&local_160);
    if (local_168 != 0) {
      FUN_180005034(&local_168);
    }
  }
  *(undefined ***)(local_110 + (longlong)*(int *)(local_118 + 4) + -8) = &PTR_FUN_18001e138;
  *(int *)((longlong)&iStack_11c + (longlong)*(int *)(local_118 + 4)) =
       *(int *)(local_118 + 4) + -0x88;
  FUN_180003a68(local_110);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>(local_108);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_90);
  FUN_18000c7f0(local_28 ^ (ulonglong)auStack_188);
  return;
}


/* Function 1800034e0 FUN_1800034e0 */

ulonglong * FUN_1800034e0(longlong param_1,ulonglong *param_2,longlong *param_3,byte param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar7 = param_3[1] + *param_3;
  lVar3 = **(longlong **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x70) & 2) == 0) {
    uVar6 = **(ulonglong **)(param_1 + 0x40);
    if ((uVar6 != 0) && (*(ulonglong *)(param_1 + 0x68) < uVar6)) {
      *(ulonglong *)(param_1 + 0x68) = uVar6;
    }
  }
  else {
    uVar6 = 0;
  }
  lVar4 = *(longlong *)(param_1 + 0x68);
  lVar5 = **(longlong **)(param_1 + 0x18);
  if (((ulonglong)(lVar4 - lVar5 >> 1) < uVar7) ||
     ((uVar7 != 0 &&
      ((((param_4 & 1) != 0 && (lVar3 == 0)) || (((param_4 & 2) != 0 && (uVar6 == 0)))))))) {
    *param_2 = 0xffffffffffffffff;
  }
  else {
    lVar1 = lVar5 + uVar7 * 2;
    if (((param_4 & 1) != 0) && (lVar3 != 0)) {
      **(longlong **)(param_1 + 0x38) = lVar1;
      **(undefined4 **)(param_1 + 0x50) = (int)(lVar4 - lVar1 >> 1);
    }
    if (((param_4 & 2) != 0) && (uVar6 != 0)) {
      iVar2 = **(int **)(param_1 + 0x58);
      lVar3 = **(longlong **)(param_1 + 0x40);
      **(longlong **)(param_1 + 0x20) = lVar5;
      **(longlong **)(param_1 + 0x40) = lVar1;
      **(undefined4 **)(param_1 + 0x58) = (int)((lVar3 + (longlong)iVar2 * 2) - lVar1 >> 1);
    }
    *param_2 = uVar7;
  }
  param_2[1] = 0;
  param_2[2] = 0;
  return param_2;
}


/* Function 1800035e0 FUN_1800035e0 */

ulonglong *
FUN_1800035e0(longlong param_1,ulonglong *param_2,longlong param_3,int param_4,byte param_5)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar2 = **(ulonglong **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x70) & 2) == 0) {
    uVar6 = **(ulonglong **)(param_1 + 0x40);
    if ((uVar6 != 0) && (*(ulonglong *)(param_1 + 0x68) < uVar6)) {
      *(ulonglong *)(param_1 + 0x68) = uVar6;
    }
  }
  else {
    uVar6 = 0;
  }
  lVar3 = *(longlong *)(param_1 + 0x68);
  lVar4 = **(longlong **)(param_1 + 0x18);
  uVar7 = lVar3 - lVar4 >> 1;
  if (param_4 == 0) {
    uVar5 = 0;
LAB_1800036a0:
    uVar5 = uVar5 + param_3;
    if ((uVar5 <= uVar7) &&
       ((uVar5 == 0 ||
        ((((param_5 & 1) == 0 || (uVar2 != 0)) && (((param_5 & 2) == 0 || (uVar6 != 0)))))))) {
      uVar7 = lVar4 + uVar5 * 2;
      if (((param_5 & 1) != 0) && (uVar2 != 0)) {
        **(ulonglong **)(param_1 + 0x38) = uVar7;
        **(undefined4 **)(param_1 + 0x50) = (int)((longlong)(lVar3 - uVar7) >> 1);
      }
      if (((param_5 & 2) != 0) && (uVar6 != 0)) {
        iVar1 = **(int **)(param_1 + 0x58);
        lVar3 = **(longlong **)(param_1 + 0x40);
        **(longlong **)(param_1 + 0x20) = lVar4;
        **(ulonglong **)(param_1 + 0x40) = uVar7;
        **(undefined4 **)(param_1 + 0x58) =
             (int)((longlong)((lVar3 + (longlong)iVar1 * 2) - uVar7) >> 1);
      }
      *param_2 = uVar5;
      goto LAB_180003720;
    }
  }
  else if (param_4 == 1) {
    if ((((param_5 & 3) != 3) &&
        ((uVar5 = uVar2, (param_5 & 1) != 0 || (uVar5 = uVar6, (param_5 & 2) != 0)))) &&
       ((uVar5 != 0 || (lVar4 == 0)))) {
      uVar5 = (longlong)(uVar5 - lVar4) >> 1;
      goto LAB_1800036a0;
    }
  }
  else {
    uVar5 = uVar7;
    if (param_4 == 2) goto LAB_1800036a0;
  }
  *param_2 = 0xffffffffffffffff;
LAB_180003720:
  param_2[1] = 0;
  param_2[2] = 0;
  return param_2;
}


/* Function 180003750 FUN_180003750 */

undefined2 FUN_180003750(longlong param_1)

{
  longlong *plVar1;
  undefined2 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined2 *puVar5;
  
  plVar1 = *(longlong **)(param_1 + 0x38);
  puVar2 = (undefined2 *)*plVar1;
  if (puVar2 != (undefined2 *)0x0) {
    if (puVar2 < puVar2 + **(int **)(param_1 + 0x50)) {
      return *puVar2;
    }
    plVar3 = *(longlong **)(param_1 + 0x40);
    if ((*plVar3 != 0) && ((*(byte *)(param_1 + 0x70) & 4) == 0)) {
      puVar5 = *(undefined2 **)(param_1 + 0x68);
      if (*(undefined2 **)(param_1 + 0x68) < (undefined2 *)*plVar3) {
        puVar5 = (undefined2 *)*plVar3;
      }
      if (puVar2 < puVar5) {
        *(undefined2 **)(param_1 + 0x68) = puVar5;
        lVar4 = *plVar1;
        *plVar1 = lVar4;
        **(undefined4 **)(param_1 + 0x50) = (int)((longlong)puVar5 - lVar4 >> 1);
        return *(undefined2 *)**(undefined8 **)(param_1 + 0x38);
      }
    }
  }
  return 0xffff;
}


/* Function 1800037c0 FUN_1800037c0 */

short FUN_1800037c0(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,
                   short param_2)

{
  ulonglong uVar1;
  
  uVar1 = **(ulonglong **)(param_1 + 0x38);
  if (((uVar1 == 0) || (uVar1 <= **(ulonglong **)(param_1 + 0x18))) ||
     ((param_2 != -1 && ((param_2 != *(short *)(uVar1 - 2) && (((byte)param_1[0x70] & 2) != 0))))))
  {
    param_2 = -1;
  }
  else {
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump(param_1,-1);
    if (param_2 == -1) {
      param_2 = 0;
    }
    else {
      *(short *)**(undefined8 **)(param_1 + 0x38) = param_2;
    }
  }
  return param_2;
}


/* Function 180003850 FUN_180003850 */

ulonglong FUN_180003850(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,
                       wchar_t param_2)

{
  ulonglong uVar1;
  void *_Src;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  uint uVar5;
  wchar_t *pwVar6;
  void *pvVar7;
  ulonglong uVar8;
  void *pvVar9;
  void *pvVar10;
  
  if (((byte)param_1[0x70] & 2) != 0) {
    return 0xffff;
  }
  pvVar9 = (void *)0x0;
  if (param_2 == L'\xffff') {
    return 0;
  }
  uVar1 = **(ulonglong **)(param_1 + 0x40);
  uVar8 = uVar1 + (longlong)**(int **)(param_1 + 0x58) * 2;
  if ((uVar1 != 0) && (uVar1 < uVar8)) {
    pwVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc(param_1);
    *pwVar6 = param_2;
    *(ulonglong *)(param_1 + 0x68) = uVar1 + 2;
    goto LAB_1800038be;
  }
  _Src = (void *)**(undefined8 **)(param_1 + 0x18);
  pvVar10 = pvVar9;
  if ((uVar1 == 0) ||
     (pvVar10 = (void *)((longlong)(uVar8 - (longlong)_Src) >> 1), pvVar10 < (void *)0x20)) {
    uVar8 = 0x40;
LAB_18000395b:
    pvVar9 = operator_new(uVar8);
  }
  else {
    if (pvVar10 < (void *)0x3fffffff) {
      uVar8 = (longlong)pvVar10 * 2;
      if (0x7fffffffffffffff < uVar8) goto LAB_180003a60;
    }
    else {
      uVar8 = 0x7fffffff;
      if ((void *)0x7ffffffe < pvVar10) {
        return 0xffff;
      }
    }
    uVar8 = uVar8 * 2;
    if (uVar8 < 0x1000) {
      if (uVar8 != 0) goto LAB_18000395b;
    }
    else {
      if (uVar8 + 0x27 <= uVar8) {
LAB_180003a60:
        FUN_180001488();
        pcVar4 = (code *)swi(3);
        uVar8 = (*pcVar4)();
        return uVar8;
      }
      pvVar7 = operator_new(uVar8 + 0x27);
      if (pvVar7 == (void *)0x0) goto LAB_180003a3e;
      pvVar9 = (void *)((longlong)pvVar7 + 0x27U & 0xffffffffffffffe0);
      *(void **)((longlong)pvVar9 - 8) = pvVar7;
    }
  }
  uVar1 = (longlong)pvVar10 * 2;
  memcpy(pvVar9,_Src,uVar1);
  pvVar10 = (void *)(uVar1 + (longlong)pvVar9);
  *(longlong *)(param_1 + 0x68) = (longlong)pvVar10 + 2;
  **(undefined8 **)(param_1 + 0x20) = pvVar9;
  **(longlong **)(param_1 + 0x40) = (longlong)pvVar10;
  **(undefined4 **)(param_1 + 0x58) =
       (int)((longlong)((uVar8 - (longlong)pvVar10) + (longlong)pvVar9) >> 1);
  if (((byte)param_1[0x70] & 4) == 0) {
    lVar2 = *(longlong *)(param_1 + 0x68);
    lVar3 = **(longlong **)(param_1 + 0x38);
    **(undefined8 **)(param_1 + 0x18) = pvVar9;
    pvVar9 = (void *)((longlong)pvVar9 + (lVar3 - (longlong)_Src >> 1) * 2);
    **(longlong **)(param_1 + 0x38) = (longlong)pvVar9;
    **(undefined4 **)(param_1 + 0x50) = (int)(lVar2 - (longlong)pvVar9 >> 1);
  }
  else {
    **(undefined8 **)(param_1 + 0x18) = pvVar9;
    **(undefined8 **)(param_1 + 0x38) = 0;
    **(undefined4 **)(param_1 + 0x50) = (int)((longlong)pvVar9 >> 1);
  }
  uVar5 = *(uint *)(param_1 + 0x70);
  if ((uVar5 & 1) != 0) {
    pvVar9 = _Src;
    if ((0xfff < uVar1) &&
       (pvVar9 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar9)))) {
LAB_180003a3e:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar9);
    uVar5 = *(uint *)(param_1 + 0x70);
  }
  *(uint *)(param_1 + 0x70) = uVar5 | 1;
  pwVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc(param_1);
  *pwVar6 = param_2;
LAB_1800038be:
  return (ulonglong)(ushort)param_2;
}


/* Function 180003a68 FUN_180003a68 */

void FUN_180003a68(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  void *pvVar1;
  void *_Memory;
  longlong lVar2;
  
  *(undefined ***)param_1 = &PTR_FUN_18001e140;
  if (((byte)param_1[0x70] & 1) != 0) {
    if (**(longlong **)(param_1 + 0x40) == 0) {
      lVar2 = **(longlong **)(param_1 + 0x38) + (longlong)**(int **)(param_1 + 0x50) * 2;
    }
    else {
      lVar2 = **(longlong **)(param_1 + 0x40) + (longlong)**(int **)(param_1 + 0x58) * 2;
    }
    pvVar1 = (void *)**(longlong **)(param_1 + 0x18);
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)((lVar2 - (longlong)pvVar1 >> 1) * 2)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  **(undefined8 **)(param_1 + 0x18) = 0;
  **(undefined8 **)(param_1 + 0x38) = 0;
  **(undefined4 **)(param_1 + 0x50) = 0;
  **(undefined8 **)(param_1 + 0x20) = 0;
  **(undefined8 **)(param_1 + 0x40) = 0;
  **(undefined4 **)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x000180003b21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  return;
}


/* Function 180003b30 FUN_180003b30 */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_180003b30(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  
  *(undefined **)param_1 = &DAT_180016cc0;
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 0x88));
  this = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 8);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>(param_1,this,false);
  *(undefined ***)(param_1 + *(int *)(*(longlong *)param_1 + 4)) = &PTR_FUN_18001e138;
  *(int *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + -4) =
       *(int *)(*(longlong *)param_1 + 4) + -0x88;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  *(undefined ***)this = &PTR_FUN_18001e140;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x78) = 4;
  return param_1;
}


/* Function 180003bd4 FUN_180003bd4 */

basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_180003bd4(basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,uint param_2)

{
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *_Memory;
  
  _Memory = param_1 + -0x98;
  *(undefined ***)(param_1 + (longlong)*(int *)(*(longlong *)_Memory + 4) + -0x98) =
       &PTR_FUN_18001e1b8;
  *(int *)(param_1 + (longlong)*(int *)(*(longlong *)_Memory + 4) + -0x9c) =
       *(int *)(*(longlong *)_Memory + 4) + -0x98;
  FUN_180003a68((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x80));
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x78));
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  if ((param_2 & 1) != 0) {
    free(_Memory);
  }
  return _Memory;
}


/* Function 180003c60 FUN_180003c60 */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_180003c60(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,uint param_2)

{
  FUN_180003a68(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 180003c94 FUN_180003c94 */

basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_180003c94(basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,uint param_2)

{
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *_Memory;
  
  _Memory = param_1 + -0x88;
  *(undefined ***)(param_1 + (longlong)*(int *)(*(longlong *)_Memory + 4) + -0x88) =
       &PTR_FUN_18001e138;
  *(int *)(param_1 + (longlong)*(int *)(*(longlong *)_Memory + 4) + -0x8c) =
       *(int *)(*(longlong *)_Memory + 4) + -0x88;
  FUN_180003a68((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x80));
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x78));
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  if ((param_2 & 1) != 0) {
    free(_Memory);
  }
  return _Memory;
}


/* Function 180003d20 FUN_180003d20 */

void FUN_180003d20(longlong *param_1)

{
  bool bVar1;
  
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx
              ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)*param_1);
  }
  if (*(longlong *)((longlong)*(int *)(*(longlong *)*param_1 + 4) + 0x48 + *param_1) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return;
}


/* Function 180003d68 FUN_180003d68 */

undefined8 *
FUN_180003d68(undefined8 *param_1,basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *param_2)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  longlong lVar1;
  bool bVar2;
  
  *param_1 = param_2;
  lVar1 = *(longlong *)param_2;
  bVar2 = false;
  if (*(longlong *)(param_2 + (longlong)*(int *)(lVar1 + 4) + 0x48) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    lVar1 = *(longlong *)param_2;
  }
  if (*(int *)(param_2 + (longlong)*(int *)(lVar1 + 4) + 0x10) == 0) {
    this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
            (param_2 + (longlong)*(int *)(lVar1 + 4) + 0x50);
    if ((this == (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0) ||
       (this == param_2)) {
      bVar2 = true;
    }
    else {
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush(this);
      bVar2 = *(int *)(param_2 + (longlong)*(int *)(*(longlong *)param_2 + 4) + 0x10) == 0;
    }
  }
  *(bool *)(param_1 + 1) = bVar2;
  return param_1;
}


/* Function 180003df4 FUN_180003df4 */

longlong * FUN_180003df4(longlong param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  void *_Src;
  
  *param_2 = 0;
  param_2[2] = 0;
  param_2[3] = 7;
  *(undefined2 *)param_2 = 0;
  if ((((byte)*(undefined4 *)(param_1 + 0x70) & 0x22) == 2) ||
     (uVar2 = **(ulonglong **)(param_1 + 0x40), uVar2 == 0)) {
    if ((*(byte *)(param_1 + 0x70) & 4) != 0) {
      return param_2;
    }
    param_3 = **(longlong **)(param_1 + 0x38);
    if (param_3 == 0) {
      return param_2;
    }
    _Src = (void *)**(longlong **)(param_1 + 0x18);
    lVar1 = ((longlong)**(int **)(param_1 + 0x50) * 2 - (longlong)_Src) + param_3;
  }
  else {
    _Src = (void *)**(longlong **)(param_1 + 0x20);
    if (uVar2 < *(ulonglong *)(param_1 + 0x68)) {
      uVar2 = *(ulonglong *)(param_1 + 0x68);
    }
    lVar1 = uVar2 - (longlong)_Src;
  }
  uVar2 = lVar1 >> 1;
  if (_Src != (void *)0x0) {
    if (uVar2 < 8) {
      param_2[2] = uVar2;
      memmove(param_2,_Src,uVar2 * 2);
      *(undefined2 *)(uVar2 * 2 + (longlong)param_2) = 0;
    }
    else {
      FUN_1800014a8(param_2,uVar2,param_3,_Src);
    }
  }
  return param_2;
}


/* Function 180003ec4 ~_Sentry_base */

/* Library Function - Multiple Matches With Same Base Name
    public: __cdecl std::basic_ostream<char,struct std::char_traits<char>
   >::_Sentry_base::~_Sentry_base(void) __ptr64
    public: __cdecl std::basic_ostream<unsigned short,struct std::char_traits<unsigned short>
   >::_Sentry_base::~_Sentry_base(void) __ptr64
    public: __cdecl std::basic_ostream<wchar_t,struct std::char_traits<wchar_t>
   >::_Sentry_base::~_Sentry_base(void) __ptr64
   
   Library: Visual Studio 2019 Release */

void ~_Sentry_base(longlong *param_1)

{
  if (*(longlong *)((longlong)*(int *)(*(longlong *)*param_1 + 4) + 0x48 + *param_1) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return;
}


/* Function 180003ef0 FUN_180003ef0 */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_180003ef0(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,wchar_t *param_2)

{
  bool bVar1;
  ushort uVar2;
  __int64 _Var3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *local_38;
  char local_30;
  
  lVar6 = 0;
  iVar5 = 0;
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (param_2[lVar7] != L'\0');
  lVar4 = *(longlong *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x28);
  if ((0 < lVar4) && (lVar7 < lVar4)) {
    lVar6 = lVar4 - lVar7;
  }
  FUN_180003d68(&local_38,param_1);
  if (local_30 == '\0') {
    iVar5 = 4;
  }
  else {
    lVar4 = *(longlong *)param_1;
    if ((*(uint *)(param_1 + (longlong)*(int *)(lVar4 + 4) + 0x18) & 0x1c0) != 0x40) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                          (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                            (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x48),
                           *(wchar_t *)
                            (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x58));
        if (uVar2 == 0xffff) goto LAB_180003fe9;
      }
      lVar4 = *(longlong *)param_1;
    }
    _Var3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                      (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                        (param_1 + (longlong)*(int *)(lVar4 + 4) + 0x48),param_2,lVar7);
    if (_Var3 == lVar7) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                          (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                            (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x48),
                           *(wchar_t *)
                            (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x58));
        if (uVar2 == 0xffff) goto LAB_180003fe9;
      }
    }
    else {
LAB_180003fe9:
      iVar5 = 4;
    }
    *(undefined8 *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x28) = 0;
  }
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (param_1 + *(int *)(*(longlong *)param_1 + 4)),iVar5,false);
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(local_38);
  }
  if (*(longlong *)(local_38 + (longlong)*(int *)(*(longlong *)local_38 + 4) + 0x48) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return param_1;
}


/* Function 18000407c FUN_18000407c */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_18000407c(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,char *param_2)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  bool bVar1;
  ushort uVar2;
  wchar_t wVar3;
  locale *plVar4;
  ctype<wchar_t> *this_00;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  longlong lVar8;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *local_60;
  char local_58;
  longlong local_48;
  
  iVar7 = 0;
  lVar8 = -1;
  do {
    lVar8 = lVar8 + 1;
  } while (param_2[lVar8] != '\0');
  lVar6 = *(longlong *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x28);
  if ((lVar6 < 1) || (lVar6 <= lVar8)) {
    lVar6 = 0;
  }
  else {
    lVar6 = lVar6 - lVar8;
  }
  FUN_180003d68(&local_60,param_1);
  if (local_58 != '\0') {
    plVar4 = (locale *)
             std::ios_base::getloc((ios_base *)(param_1 + *(int *)(*(longlong *)param_1 + 4)));
    this_00 = (ctype<wchar_t> *)FUN_180004460(plVar4);
    if ((local_48 != 0) && (lVar5 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(), lVar5 != 0)) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5,1);
    }
    if ((*(uint *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x18) & 0x1c0) != 0x40)
    {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                          (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                            (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x48),
                           *(wchar_t *)
                            (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x58));
        if (uVar2 == 0xffff) {
          iVar7 = 4;
          break;
        }
      }
    }
    do {
      if (iVar7 != 0) goto LAB_180004219;
      if (lVar8 < 1) goto LAB_1800041ed;
      this = *(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
              (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x48);
      wVar3 = std::ctype<wchar_t>::widen(this_00,*param_2);
      uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc(this,wVar3);
      if (uVar2 == 0xffff) {
        iVar7 = 4;
      }
      lVar8 = lVar8 + -1;
      param_2 = param_2 + 1;
    } while( true );
  }
  iVar7 = 4;
LAB_18000423c:
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (param_1 + *(int *)(*(longlong *)param_1 + 4)),iVar7,false);
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(local_60);
  }
  if (*(longlong *)(local_60 + (longlong)*(int *)(*(longlong *)local_60 + 4) + 0x48) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return param_1;
LAB_1800041ed:
  if (lVar6 < 1) goto LAB_180004219;
  uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                    (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                      (param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x48),
                     *(wchar_t *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x58));
  if (uVar2 == 0xffff) {
    iVar7 = 4;
    goto LAB_180004219;
  }
  lVar6 = lVar6 + -1;
  goto LAB_1800041ed;
LAB_180004219:
  *(undefined8 *)(param_1 + (longlong)*(int *)(*(longlong *)param_1 + 4) + 0x28) = 0;
  goto LAB_18000423c;
}


/* Function 1800042a0 FUN_1800042a0 */

void FUN_1800042a0(longlong param_1,uint param_2)

{
  FUN_180003bd4((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
                (param_1 - *(int *)(param_1 + -4)),param_2);
  return;
}


/* Function 1800042b0 FUN_1800042b0 */

void FUN_1800042b0(longlong param_1,uint param_2)

{
  FUN_180003c94((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
                (param_1 - *(int *)(param_1 + -4)),param_2);
  return;
}


/* Function 1800042bc FUN_1800042bc */

undefined8 *
FUN_1800042bc(undefined8 *param_1,ulonglong param_2,undefined8 param_3,void *param_4,
             longlong param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  code *pcVar4;
  size_t _Size;
  void *pvVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  void *_Dst;
  ulonglong uVar8;
  void *_Memory;
  
  lVar2 = param_1[2];
  uVar8 = 0x7ffffffffffffffe;
  if (0x7ffffffffffffffeU - lVar2 < param_2) {
    FUN_180001320();
    pcVar4 = (code *)swi(3);
    puVar6 = (undefined8 *)(*pcVar4)();
    return puVar6;
  }
  uVar3 = param_1[3];
  uVar7 = param_2 + lVar2 | 7;
  if ((uVar7 < 0x7fffffffffffffff) && (uVar3 <= 0x7ffffffffffffffe - (uVar3 >> 1))) {
    uVar1 = (uVar3 >> 1) + uVar3;
    uVar8 = uVar7;
    if (uVar7 < uVar1) {
      uVar8 = uVar1;
    }
    if (0x7fffffffffffffff < uVar8 + 1) goto LAB_180004459;
    uVar7 = (uVar8 + 1) * 2;
    if (0xfff < uVar7) goto LAB_180004354;
    _Dst = (void *)0x0;
    if (uVar7 != 0) {
      _Dst = operator_new(uVar7);
    }
  }
  else {
    uVar7 = 0xfffffffffffffffe;
LAB_180004354:
    if (uVar7 + 0x27 <= uVar7) {
LAB_180004459:
      FUN_180001488();
      pcVar4 = (code *)swi(3);
      puVar6 = (undefined8 *)(*pcVar4)();
      return puVar6;
    }
    pvVar5 = operator_new(uVar7 + 0x27);
    if (pvVar5 == (void *)0x0) goto LAB_180004411;
    _Dst = (void *)((longlong)pvVar5 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)_Dst - 8) = pvVar5;
  }
  _Size = lVar2 * 2;
  param_1[2] = param_2 + lVar2;
  param_1[3] = uVar8;
  if (uVar3 < 8) {
    memcpy(_Dst,param_1,_Size);
    memcpy((void *)(_Size + (longlong)_Dst),param_4,param_5 * 2);
    *(undefined2 *)((longlong)_Dst + (lVar2 + param_5) * 2) = 0;
  }
  else {
    pvVar5 = (void *)*param_1;
    memcpy(_Dst,pvVar5,_Size);
    memcpy((void *)(_Size + (longlong)_Dst),param_4,param_5 * 2);
    *(undefined2 *)((longlong)_Dst + (lVar2 + param_5) * 2) = 0;
    _Memory = pvVar5;
    if ((0xfff < uVar3 * 2 + 2) &&
       (_Memory = *(void **)((longlong)pvVar5 + -8),
       0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)_Memory)))) {
LAB_180004411:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  *param_1 = _Dst;
  return param_1;
}


/* Function 180004460 FUN_180004460 */

void FUN_180004460(locale *param_1)

{
  longlong lVar1;
  code *pcVar2;
  _Facet_base *p_Var3;
  __uint64 _Var4;
  _Locimp *p_Var5;
  longlong lVar6;
  undefined1 auStack_48 [32];
  _Facet_base *local_28;
  _Lockit local_20 [8];
  _Facet_base *local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_48;
  std::_Lockit::_Lockit(local_20,0);
  local_28 = DAT_18001f550;
  _Var4 = std::locale::id::operator_unsigned___int64((id *)id_exref);
  lVar1 = *(longlong *)(param_1 + 8);
  if ((_Var4 < *(ulonglong *)(lVar1 + 0x18)) &&
     (*(longlong *)(*(longlong *)(lVar1 + 0x10) + _Var4 * 8) != 0)) goto LAB_180004531;
  lVar6 = 0;
  if (*(char *)(lVar1 + 0x24) == '\0') {
LAB_1800044e0:
    if (lVar6 != 0) goto LAB_180004531;
  }
  else {
    p_Var5 = std::locale::_Getgloballocale();
    if (_Var4 < *(ulonglong *)(p_Var5 + 0x18)) {
      lVar6 = *(longlong *)(*(longlong *)(p_Var5 + 0x10) + _Var4 * 8);
      goto LAB_1800044e0;
    }
  }
  if (local_28 == (_Facet_base *)0x0) {
    _Var4 = std::ctype<wchar_t>::_Getcat((facet **)&local_28,param_1);
    p_Var3 = local_28;
    if (_Var4 == 0xffffffffffffffff) {
      FUN_1800045c4();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    local_18 = local_28;
    std::_Facet_Register(local_28);
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(p_Var3);
    DAT_18001f550 = local_28;
  }
LAB_180004531:
  std::_Lockit::~_Lockit(local_20);
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_48);
  return;
}


/* Function 180004564 FUN_180004564 */

undefined8 * FUN_180004564(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad cast";
  *param_1 = &PTR_FUN_18001e128;
  return param_1;
}


/* Function 180004584 FUN_180004584 */

undefined8 * FUN_180004584(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = &PTR_FUN_18001e128;
  return param_1;
}


/* Function 1800045c4 FUN_1800045c4 */

void FUN_1800045c4(void)

{
  undefined8 local_28 [5];
  
  FUN_180004564(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001a958);
}


/* Function 1800045e4 FUN_1800045e4 */

void FUN_1800045e4(longlong *param_1)

{
  if (*param_1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,1);
  }
  return;
}


/* Function 180004608 ~locale */

/* Library Function - Single Match
    public: __cdecl std::locale::~locale(void) __ptr64
   
   Library: Visual Studio 2019 Release */

void __thiscall std::locale::~locale(locale *this)

{
  longlong lVar1;
  
  if (*(longlong *)(this + 8) != 0) {
    lVar1 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (lVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1,1);
    }
  }
  return;
}


/* Function 180004644 FUN_180004644 */

void FUN_180004644(undefined8 *param_1,longlong param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  wint_t *pwVar5;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  ulonglong local_20;
  ulonglong uVar4;
  
  local_20 = DAT_18001e100 ^ (ulonglong)auStack_48;
  uVar4 = (ulonglong)param_3;
  pwVar5 = (wint_t *)(param_2 + -2 + uVar4 * 2);
  if (param_3 != 0) {
    do {
      iVar2 = iswspace(*pwVar5);
      if (iVar2 == 0) break;
      pwVar5 = pwVar5 + -1;
      uVar3 = (int)uVar4 - 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 != 0);
  }
  local_28 = 0;
  iVar2 = WindowsCreateString(param_2,uVar4,&local_28);
  if (-1 < iVar2) {
    *param_1 = local_28;
    FUN_18000c7f0(local_20 ^ (ulonglong)auStack_48);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800046d4 FUN_1800046d4 */

void FUN_1800046d4(longlong *param_1)

{
  if (*param_1 != 0) {
    WindowsDeleteString();
    *param_1 = 0;
  }
  return;
}


/* Function 1800046f4 FUN_1800046f4 */

void FUN_1800046f4(longlong param_1,undefined8 *param_2)

{
  LPVOID lpMem;
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  HANDLE hHeap;
  BSTR pOVar4;
  undefined1 auStackY_88 [32];
  BSTR local_48;
  BSTR local_40;
  BSTR local_38;
  int local_30 [2];
  LPVOID local_28;
  ulonglong local_20;
  
  local_20 = DAT_18001e100 ^ (ulonglong)auStackY_88;
  if (*(longlong *)(param_1 + 0x10) != 0) {
    local_30[0] = 0;
    local_38 = (BSTR)0x0;
    local_48 = (BSTR)0x0;
    local_40 = (BSTR)0x0;
    iVar1 = (*(code *)PTR__guard_dispatch_icall_1800165a8)
                      (*(longlong *)(param_1 + 0x10),&local_38,local_30,&local_48);
    if ((iVar1 == 0) && (local_30[0] == *(int *)(param_1 + 0xc))) {
      if (local_48 == (BSTR)0x0) {
        uVar2 = SysStringLen(local_38);
        pOVar4 = local_38;
      }
      else {
        uVar2 = SysStringLen(local_48);
        pOVar4 = local_48;
      }
      FUN_180004644(param_2,(longlong)pOVar4,uVar2);
      if (local_40 != (BSTR)0x0) {
        SysFreeString(local_40);
        local_40 = (BSTR)0x0;
      }
      if (local_48 != (BSTR)0x0) {
        SysFreeString(local_48);
        local_48 = (BSTR)0x0;
      }
      if (local_38 != (BSTR)0x0) {
        SysFreeString(local_38);
      }
      goto LAB_180004852;
    }
    if (local_40 != (BSTR)0x0) {
      SysFreeString(local_40);
      local_40 = (BSTR)0x0;
    }
    if (local_48 != (BSTR)0x0) {
      SysFreeString(local_48);
      local_48 = (BSTR)0x0;
    }
    if (local_38 != (BSTR)0x0) {
      SysFreeString(local_38);
    }
  }
  local_28 = (LPVOID)0x0;
  DVar3 = FormatMessageW(0x1300,(LPCVOID)0x0,*(DWORD *)(param_1 + 0xc),0x400,(LPWSTR)&local_28,0,
                         (va_list *)0x0);
  FUN_180004644(param_2,(longlong)local_28,DVar3);
  lpMem = local_28;
  if (local_28 != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
LAB_180004852:
  FUN_18000c7f0(local_20 ^ (ulonglong)auStackY_88);
  return;
}


/* Function 180004874 FUN_180004874 */

undefined4 FUN_180004874(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x40);
}


/* Function 180004878 FUN_180004878 */

longlong * FUN_180004878(longlong *param_1,void *param_2,undefined8 param_3)

{
  ulonglong uVar1;
  
  param_1[3] = 7;
  *param_1 = 0;
  param_1[2] = 0;
  uVar1 = 0xffffffffffffffff;
  do {
    uVar1 = uVar1 + 1;
  } while (*(short *)((longlong)param_2 + uVar1 * 2) != 0);
  if (uVar1 < 8) {
    param_1[2] = uVar1;
    memmove(param_1,param_2,uVar1 * 2);
    *(undefined2 *)(uVar1 * 2 + (longlong)param_1) = 0;
  }
  else {
    FUN_1800014a8(param_1,uVar1,param_3,param_2);
  }
  return param_1;
}


/* Function 1800048e4 FUN_1800048e4 */

void FUN_1800048e4(undefined8 *param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined1 local_20 [8];
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_28 = 0;
  iVar2 = RoGetActivationFactory(*param_2,&DAT_180016ce0,&local_28);
  if (iVar2 == -0x7ffbfe10) {
    CoIncrementMTAUsage(local_20);
    iVar2 = RoGetActivationFactory(*param_2,&DAT_180016ce0,&local_28);
  }
  if (-1 < iVar2) {
    *param_1 = local_28;
    FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180004980 FUN_180004980 */

void FUN_180004980(undefined8 *param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_48 [32];
  undefined8 *local_28;
  undefined8 *local_20;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_20 = (undefined8 *)0x0;
  local_28 = param_2;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,&local_20);
  if (-1 < iVar2) {
    if (local_20 == (undefined8 *)0x0) {
      *param_2 = 0;
    }
    else {
      local_28 = (undefined8 *)0x0;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)
                (local_20,&DAT_180016d50,&local_28,*(undefined8 *)*local_20);
      *param_2 = local_28;
    }
    if (local_20 != (undefined8 *)0x0) {
      FUN_180005034(&local_20);
    }
    FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180004a2c FUN_180004a2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180004a2c(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 auStack_78 [32];
  longlong local_58;
  longlong local_50;
  undefined *local_48;
  undefined *local_40;
  undefined8 local_38;
  undefined1 local_30 [24];
  longlong local_18;
  ulonglong local_10;
  
  lVar2 = _DAT_18001f568;
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_78;
  local_48 = &DAT_18001f568;
  LOCK();
  _DAT_18001f568 = _DAT_18001f568 + 1;
  UNLOCK();
  if (DAT_18001f560 == 0) {
    LOCK();
    UNLOCK();
    _DAT_18001f568 = lVar2;
    iVar1 = WindowsCreateStringReference
                      (L"Windows.Foundation.Diagnostics.LoggingFields",0x2c,local_30,&local_38);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      terminate();
    }
    FUN_1800048e4(&local_58,&local_38);
    if (local_58 == 0) {
      local_50 = 0;
    }
    else {
      local_18 = 0;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_58,&DAT_180016ec0,&local_18);
      local_50 = local_18;
    }
    if (local_50 == 0) {
      FUN_180004980(&local_58,param_1);
      lVar2 = local_58;
    }
    else {
      FUN_180005034(&local_50);
      local_40 = &DAT_18001f568;
      LOCK();
      _DAT_18001f568 = _DAT_18001f568 + 1;
      UNLOCK();
      LOCK();
      bVar3 = DAT_18001f560 == 0;
      if (bVar3) {
        DAT_18001f560 = local_58;
      }
      UNLOCK();
      lVar2 = local_58;
      if (bVar3) {
        local_58 = 0;
        InterlockedPushEntrySList((PSLIST_HEADER)&DAT_18001f5c0,(PSLIST_ENTRY)&DAT_18001f570);
        lVar2 = 0;
      }
      FUN_180004980(&DAT_18001f560,param_1);
      LOCK();
      _DAT_18001f568 = _DAT_18001f568 + -1;
      UNLOCK();
    }
    if (lVar2 != 0) {
      FUN_180005034(&local_58);
    }
  }
  else {
    FUN_180004980(&DAT_18001f560,param_1);
    LOCK();
    _DAT_18001f568 = _DAT_18001f568 + -1;
    UNLOCK();
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* Function 180004bb0 FUN_180004bb0 */

void FUN_180004bb0(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,param_3,&local_18);
  if (-1 < iVar2) {
    *param_2 = local_18;
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180004c18 FUN_180004c18 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180004c18(undefined8 *param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 auStack_a8 [32];
  longlong local_88;
  longlong local_80;
  undefined *local_78;
  undefined *local_70;
  undefined8 local_68;
  undefined1 local_60 [24];
  longlong local_48;
  longlong local_40;
  undefined1 local_38 [8];
  ulonglong local_30;
  
  lVar3 = _DAT_18001f588;
  local_30 = DAT_18001e100 ^ (ulonglong)auStack_a8;
  local_78 = &DAT_18001f588;
  LOCK();
  _DAT_18001f588 = _DAT_18001f588 + 1;
  UNLOCK();
  if (DAT_18001f580 == 0) {
    LOCK();
    UNLOCK();
    _DAT_18001f588 = lVar3;
    iVar2 = WindowsCreateStringReference
                      (L"Windows.Foundation.Diagnostics.LoggingOptions",0x2d,local_60,&local_68);
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      terminate();
    }
    local_48 = 0;
    iVar2 = RoGetActivationFactory(local_68,&DAT_180016d60,&local_48);
    if (iVar2 == -0x7ffbfe10) {
      CoIncrementMTAUsage(local_38);
      iVar2 = RoGetActivationFactory(local_68,&DAT_180016d60,&local_48);
    }
    lVar3 = local_48;
    if (iVar2 < 0) {
      FUN_18000533c(iVar2);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    local_88 = local_48;
    if (local_48 == 0) {
      local_80 = 0;
    }
    else {
      local_40 = 0;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_48,&DAT_180016ec0,&local_40);
      local_80 = local_40;
    }
    if (local_80 == 0) {
      FUN_180004bb0(&local_88,param_1,*(undefined8 *)*param_2);
      lVar3 = local_88;
    }
    else {
      FUN_180005034(&local_80);
      local_70 = &DAT_18001f588;
      LOCK();
      _DAT_18001f588 = _DAT_18001f588 + 1;
      UNLOCK();
      LOCK();
      bVar4 = DAT_18001f580 == 0;
      if (bVar4) {
        DAT_18001f580 = lVar3;
      }
      UNLOCK();
      if (bVar4) {
        local_88 = 0;
        InterlockedPushEntrySList((PSLIST_HEADER)&DAT_18001f5c0,(PSLIST_ENTRY)&DAT_18001f590);
        lVar3 = 0;
      }
      FUN_180004bb0(&DAT_18001f580,param_1,*(undefined8 *)*param_2);
      LOCK();
      _DAT_18001f588 = _DAT_18001f588 + -1;
      UNLOCK();
    }
    if (lVar3 != 0) {
      FUN_180005034(&local_88);
    }
  }
  else {
    FUN_180004bb0(&DAT_18001f580,param_1,*(undefined8 *)*param_2);
    LOCK();
    _DAT_18001f588 = _DAT_18001f588 + -1;
    UNLOCK();
  }
  FUN_18000c7f0(local_30 ^ (ulonglong)auStack_a8);
  return;
}


/* Function 180004df0 FUN_180004df0 */

void FUN_180004df0(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_28 = *param_3;
  uStack_24 = param_3[1];
  uStack_20 = param_3[2];
  uStack_1c = param_3[3];
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,&local_28,&local_18);
  if (-1 < iVar2) {
    *param_2 = local_18;
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_48);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180004e64 FUN_180004e64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180004e64(undefined8 *param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 auStack_a8 [32];
  longlong local_88;
  longlong local_80;
  undefined *local_78;
  undefined *local_70;
  undefined8 local_68;
  undefined1 local_60 [24];
  longlong local_48;
  longlong local_40;
  undefined1 local_38 [8];
  ulonglong local_30;
  
  lVar3 = _DAT_18001f5a8;
  local_30 = DAT_18001e100 ^ (ulonglong)auStack_a8;
  local_78 = &DAT_18001f5a8;
  LOCK();
  _DAT_18001f5a8 = _DAT_18001f5a8 + 1;
  UNLOCK();
  if (DAT_18001f5a0 == 0) {
    LOCK();
    UNLOCK();
    _DAT_18001f5a8 = lVar3;
    iVar2 = WindowsCreateStringReference
                      (L"Windows.Foundation.Diagnostics.LoggingChannelOptions",0x34,local_60,
                       &local_68);
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      terminate();
    }
    local_48 = 0;
    iVar2 = RoGetActivationFactory(local_68,&DAT_180016dd0,&local_48);
    if (iVar2 == -0x7ffbfe10) {
      CoIncrementMTAUsage(local_38);
      iVar2 = RoGetActivationFactory(local_68,&DAT_180016dd0,&local_48);
    }
    lVar3 = local_48;
    if (iVar2 < 0) {
      FUN_18000533c(iVar2);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    local_88 = local_48;
    if (local_48 == 0) {
      local_80 = 0;
    }
    else {
      local_40 = 0;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_48,&DAT_180016ec0,&local_40);
      local_80 = local_40;
    }
    if (local_80 == 0) {
      FUN_180004df0(&local_88,param_1,(undefined4 *)*param_2);
      lVar3 = local_88;
    }
    else {
      FUN_180005034(&local_80);
      local_70 = &DAT_18001f5a8;
      LOCK();
      _DAT_18001f5a8 = _DAT_18001f5a8 + 1;
      UNLOCK();
      LOCK();
      bVar4 = DAT_18001f5a0 == 0;
      if (bVar4) {
        DAT_18001f5a0 = lVar3;
      }
      UNLOCK();
      if (bVar4) {
        local_88 = 0;
        InterlockedPushEntrySList((PSLIST_HEADER)&DAT_18001f5c0,(PSLIST_ENTRY)&DAT_18001f5b0);
        lVar3 = 0;
      }
      FUN_180004df0(&DAT_18001f5a0,param_1,(undefined4 *)*param_2);
      LOCK();
      _DAT_18001f5a8 = _DAT_18001f5a8 + -1;
      UNLOCK();
    }
    if (lVar3 != 0) {
      FUN_180005034(&local_88);
    }
  }
  else {
    FUN_180004df0(&DAT_18001f5a0,param_1,(undefined4 *)*param_2);
    LOCK();
    _DAT_18001f5a8 = _DAT_18001f5a8 + -1;
    UNLOCK();
  }
  FUN_18000c7f0(local_30 ^ (ulonglong)auStack_a8);
  return;
}


/* Function 180005034 FUN_180005034 */

/* WARNING: Switch with 1 destination removed at 0x000180005045 */

void FUN_180005034(undefined8 *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)*param_1;
  *param_1 = 0;
                    /* WARNING: Could not recover jumptable at 0x000180012b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar1 + 0x10))(plVar1);
  return;
}


/* Function 18000504c FUN_18000504c */

undefined8 * FUN_18000504c(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad allocation";
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}


/* Function 18000506c FUN_18000506c */

undefined8 * FUN_18000506c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016ee0);
  return param_1;
}


/* Function 18000508c FUN_18000508c */

void FUN_18000508c(undefined8 *param_1)

{
  if (param_1[2] != 0) {
    FUN_180005034(param_1 + 2);
  }
  if ((BSTR)*param_1 != (BSTR)0x0) {
    SysFreeString((BSTR)*param_1);
    *param_1 = 0;
  }
  return;
}


/* Function 1800050bc FUN_1800050bc */

undefined8 * FUN_1800050bc(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0xaabbccdd;
  *(undefined4 *)((longlong)param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  lVar1 = *(longlong *)(param_2 + 0x10);
  param_1[2] = lVar1;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return param_1;
}


/* Function 1800050fc FUN_1800050fc */

undefined8 * FUN_1800050fc(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016ee4);
  return param_1;
}


/* Function 18000511c FUN_18000511c */

undefined8 * FUN_18000511c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016ee8);
  return param_1;
}


/* Function 18000513c FUN_18000513c */

undefined8 * FUN_18000513c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016eec);
  return param_1;
}


/* Function 18000515c FUN_18000515c */

undefined8 * FUN_18000515c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016ef0);
  return param_1;
}


/* Function 18000517c FUN_18000517c */

undefined8 * FUN_18000517c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016ef4);
  return param_1;
}


/* Function 18000519c FUN_18000519c */

undefined8 * FUN_18000519c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016ef8);
  return param_1;
}


/* Function 1800051bc FUN_1800051bc */

undefined8 * FUN_1800051bc(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016efc);
  return param_1;
}


/* Function 1800051dc FUN_1800051dc */

undefined8 * FUN_1800051dc(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016f00);
  return param_1;
}


/* Function 1800051fc FUN_1800051fc */

undefined8 * FUN_1800051fc(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016f04);
  return param_1;
}


/* Function 18000521c FUN_18000521c */

undefined8 * FUN_18000521c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016f08);
  return param_1;
}


/* Function 18000523c FUN_18000523c */

undefined8 * FUN_18000523c(undefined8 *param_1)

{
  FUN_18000525c(param_1,DAT_180016f0c);
  return param_1;
}


/* Function 18000525c FUN_18000525c */

void FUN_18000525c(undefined8 *param_1,undefined4 param_2)

{
  longlong *plVar1;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  *param_1 = 0;
  plVar1 = param_1 + 2;
  *(undefined4 *)((longlong)param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 1) = 0xaabbccdd;
  *plVar1 = 0;
  GetRestrictedErrorInfo(plVar1);
  if (*plVar1 == 0) {
    RoOriginateLanguageException(param_2,0,0);
    GetRestrictedErrorInfo(plVar1);
  }
  else {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(*plVar1,param_1);
    if (*plVar1 != 0) {
      local_18 = 0;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(*plVar1,&DAT_180016f10,&local_18);
      if (local_18 != 0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18,0);
        FUN_180005034(&local_18);
      }
    }
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
  return;
}


/* Function 18000533c FUN_18000533c */

void FUN_18000533c(int param_1)

{
  undefined8 local_28 [4];
  
  if (param_1 == -0x7ff8fff2) {
    FUN_18000504c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001a990);
  }
  if (param_1 == -0x7ff8fffb) {
    FUN_18000506c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001a9f0);
  }
  if (param_1 == -0x7ffefef2) {
    FUN_1800050fc(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001aa50);
  }
  if (param_1 == -0x7fffbfff) {
    FUN_18000511c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001aab0);
  }
  if (param_1 == -0x7ff8ffa9) {
    FUN_18000513c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001ab10);
  }
  if (param_1 == -0x7ffffff5) {
    FUN_18000515c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001ab70);
  }
  if (param_1 == -0x7fffbffe) {
    FUN_18000517c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001abd0);
  }
  if (param_1 == -0x7ffbfeef) {
    FUN_18000519c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001ac30);
  }
  if (param_1 == -0x7ffffff4) {
    FUN_1800051bc(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001ac90);
  }
  if (param_1 == -0x7ffffff2) {
    FUN_1800051dc(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001acf0);
  }
  if (param_1 == -0x7ffffff3) {
    FUN_1800051fc(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001ad50);
  }
  if (param_1 == -0x7fffffe8) {
    FUN_18000521c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001adb0);
  }
  if (param_1 == -0x7ff8fb39) {
    FUN_18000523c(local_28);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001ae10);
  }
  FUN_18000525c(local_28,param_1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001ae68);
}


/* Function 18000551c FUN_18000551c */

void FUN_18000551c(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined4 *param_5)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_68 [32];
  undefined8 *local_48;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = DAT_18001e100 ^ (ulonglong)auStack_68;
  local_28 = 0;
  local_38 = *param_5;
  uStack_34 = param_5[1];
  uStack_30 = param_5[2];
  uStack_2c = param_5[3];
  local_48 = &local_28;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,*param_3,*param_4,&local_38);
  if (-1 < iVar2) {
    *param_2 = local_28;
    FUN_18000c7f0(local_20 ^ (ulonglong)auStack_68);
    return;
  }
  FUN_18000533c(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800055ac FUN_1800055ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800055ac(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 auStackY_a8 [32];
  longlong local_78;
  longlong local_70;
  undefined *local_68;
  undefined *local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  longlong local_38;
  longlong local_30;
  undefined1 local_28 [8];
  ulonglong local_20;
  
  lVar3 = _DAT_18001f5d8;
  local_20 = DAT_18001e100 ^ (ulonglong)auStackY_a8;
  local_68 = &DAT_18001f5d8;
  LOCK();
  _DAT_18001f5d8 = _DAT_18001f5d8 + 1;
  UNLOCK();
  if (DAT_18001f5d0 == 0) {
    LOCK();
    UNLOCK();
    _DAT_18001f5d8 = lVar3;
    iVar2 = WindowsCreateStringReference
                      (L"Windows.Foundation.Diagnostics.LoggingChannel",0x2d,local_50,&local_58);
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      terminate();
    }
    local_38 = 0;
    iVar2 = RoGetActivationFactory(local_58,&DAT_180016e50,&local_38);
    if (iVar2 == -0x7ffbfe10) {
      CoIncrementMTAUsage(local_28);
      iVar2 = RoGetActivationFactory(local_58,&DAT_180016e50,&local_38);
    }
    if (iVar2 < 0) {
      FUN_18000533c(iVar2);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    local_78 = local_38;
    if (local_38 == 0) {
      local_70 = 0;
    }
    else {
      local_30 = 0;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_38,&DAT_180016ec0,&local_30);
      local_70 = local_30;
    }
    if (local_70 == 0) {
      FUN_18000551c(&local_78,param_2,(undefined8 *)*param_3,(undefined8 *)param_3[1],
                    (undefined4 *)param_3[2]);
      lVar3 = local_78;
    }
    else {
      FUN_180005034(&local_70);
      local_60 = &DAT_18001f5d8;
      LOCK();
      _DAT_18001f5d8 = _DAT_18001f5d8 + 1;
      UNLOCK();
      LOCK();
      bVar4 = DAT_18001f5d0 == 0;
      if (bVar4) {
        DAT_18001f5d0 = local_38;
      }
      UNLOCK();
      lVar3 = local_38;
      if (bVar4) {
        local_78 = 0;
        InterlockedPushEntrySList((PSLIST_HEADER)&DAT_18001f5c0,(PSLIST_ENTRY)&DAT_18001f5e0);
        lVar3 = 0;
      }
      FUN_18000551c(&DAT_18001f5d0,param_2,(undefined8 *)*param_3,(undefined8 *)param_3[1],
                    (undefined4 *)param_3[2]);
      LOCK();
      _DAT_18001f5d8 = _DAT_18001f5d8 + -1;
      UNLOCK();
    }
    if (lVar3 != 0) {
      FUN_180005034(&local_78);
    }
  }
  else {
    FUN_18000551c(&DAT_18001f5d0,param_2,(undefined8 *)*param_3,(undefined8 *)param_3[1],
                  (undefined4 *)param_3[2]);
    LOCK();
    _DAT_18001f5d8 = _DAT_18001f5d8 + -1;
    UNLOCK();
  }
  FUN_18000c7f0(local_20 ^ (ulonglong)auStackY_a8);
  return;
}


/* Function 1800057a8 FUN_1800057a8 */

undefined8 * FUN_1800057a8(undefined8 *param_1)

{
  longlong lVar1;
  
  Platform::Object::Object((Object *)(param_1 + 2));
  lVar1 = DAT_18001eee0;
  *param_1 = &PTR_FUN_18001e660;
  param_1[1] = &PTR_FUN_18001e620;
  param_1[2] = &PTR_FUN_18001e5f0;
  param_1[3] = &PTR_FUN_18001e5c8;
  param_1[4] = &PTR_FUN_18001e598;
  param_1[8] = 0xffffffffffffffff;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}


/* Function 180005830 FUN_180005830 */

undefined8 * FUN_180005830(undefined8 *param_1)

{
  longlong lVar1;
  
  Platform::Object::Object((Object *)(param_1 + 1));
  lVar1 = DAT_18001eee0;
  *param_1 = &PTR_FUN_18001e558;
  param_1[1] = &PTR_FUN_18001e528;
  param_1[3] = 0xffffffffffffffff;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return param_1;
}


/* Function 18000588c FUN_18000588c */

void FUN_18000588c(longlong *param_1,undefined8 param_2,size_t param_3)

{
  int iVar1;
  void *pvVar2;
  longlong *plVar3;
  size_t sVar4;
  int *piVar5;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  longlong local_b0 [4];
  longlong *local_90;
  int local_88 [4];
  wchar_t local_78 [40];
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStack_d8;
  local_b8 = 0;
  sVar4 = param_3;
  local_90 = param_1;
  FUN_1800011a0(local_78,L"`anonymous-namespace\'::GetAppUri",param_3,0x29);
  FUN_180004878(param_1,
                L"ms-screensketch:edit?&amp;source=Toast&amp;isTemporary=true&amp;sharedAccessToken="
                ,sVar4);
  local_b8 = 1;
  pvVar2 = (void *)WindowsGetStringRawBuffer(param_2,0);
  plVar3 = FUN_180004878(local_b0,pvVar2,sVar4);
  FUN_18000c2fc(param_1,plVar3,sVar4);
  FUN_1800015f0(local_b0);
  local_88[0] = 0;
  piVar5 = local_88;
  WindowsCompareStringOrdinal(param_3,0);
  if (local_88[0] != 0) {
    iVar1 = WindowsIsStringEmpty(param_3);
    if (iVar1 == 0) {
      plVar3 = FUN_180004878(local_b0,L"&amp;secondarySharedAccessToken=",piVar5);
      FUN_18000c2fc(param_1,plVar3,piVar5);
      FUN_1800015f0(local_b0);
      pvVar2 = (void *)WindowsGetStringRawBuffer(param_3,0);
      plVar3 = FUN_180004878(local_b0,pvVar2,piVar5);
      FUN_18000c2fc(param_1,plVar3,piVar5);
      FUN_1800015f0(local_b0);
    }
  }
  FUN_1800012bc(local_78);
  FUN_18000c7f0(local_28 ^ (ulonglong)auStack_d8);
  return;
}


/* Function 1800059bc FUN_1800059bc */

void FUN_1800059bc(undefined8 param_1,undefined8 param_2,size_t param_3,undefined8 param_4,
                  undefined8 param_5)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  void *pvVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 ****ppppuVar13;
  longlong lVar14;
  undefined8 uVar15;
  wchar_t *pwVar16;
  wchar_t ****ppppwVar17;
  undefined1 *puVar18;
  undefined1 auStackY_398 [32];
  undefined8 ***local_340 [2];
  longlong local_330;
  ulonglong uStack_328;
  undefined8 local_320;
  longlong local_318 [3];
  undefined8 local_300;
  longlong local_2f8 [4];
  longlong local_2d8 [4];
  longlong local_2b8 [4];
  longlong local_298 [4];
  longlong local_278 [4];
  longlong local_258 [4];
  longlong local_238 [4];
  longlong local_218 [4];
  longlong local_1f8 [4];
  longlong local_1d8 [4];
  longlong local_1b8 [4];
  longlong local_198 [4];
  longlong local_178 [4];
  undefined1 local_158 [24];
  longlong *local_140;
  undefined8 local_138;
  longlong local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined8 **local_110;
  undefined8 **ppuStack_108;
  undefined8 **local_100;
  undefined8 **ppuStack_f8;
  longlong local_f0 [2];
  longlong local_e0;
  wchar_t ***local_d0 [3];
  ulonglong local_b8;
  wchar_t local_a8 [40];
  ulonglong local_58;
  
  local_58 = DAT_18001e100 ^ (ulonglong)auStackY_398;
  FUN_1800011a0(local_a8,L"`anonymous-namespace\'::CreateAndShowToast",param_3,0x49);
  FUN_18000588c(local_f0,param_2,param_3);
  local_130 = 0x498964660cc04141;
  local_128 = 0x820b9494;
  local_124 = 0x1f3fc5df;
  local_140 = (longlong *)0x0;
  iVar3 = GetActivationFactoryByPCWSTR
                    (L"Windows.ApplicationModel.Resources.ResourceLoader",(Guid *)&local_130,
                     &local_140);
  if (iVar3 < 0) {
LAB_18000625a:
    iVar3 = FUN_180001ad4(iVar3);
LAB_180006262:
    iVar3 = FUN_180001ad4(iVar3);
LAB_18000626a:
    FUN_180001ad4(iVar3);
LAB_180006272:
    iVar3 = FUN_180001320();
LAB_180006278:
    iVar3 = FUN_180001ad4(iVar3);
LAB_180006280:
    iVar3 = FUN_180001ad4(iVar3);
LAB_180006288:
    iVar3 = FUN_180001ad4(iVar3);
  }
  else {
    plVar4 = (longlong *)FUN_180008134(local_140);
    if (plVar4 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
    }
    if (local_140 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    puVar18 = local_158;
    iVar3 = WindowsCreateStringReference(L"ToastImageDescription",0x15,puVar18,&local_138);
    if (iVar3 < 0) goto LAB_180006262;
    lVar5 = FUN_1800080b4(plVar4,local_138);
    if (lVar5 != 0) {
      iVar3 = WindowsDuplicateString(lVar5,&local_138);
      if (-1 < iVar3) {
        local_320 = local_138;
        goto LAB_180005b7b;
      }
      goto LAB_18000626a;
    }
    local_320 = 0;
LAB_180005b7b:
    uVar2 = local_320;
    WindowsDeleteString(lVar5);
    if (plVar4 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
    }
    plVar4 = FUN_180004878(local_178,L"</text></binding></visual></toast>",puVar18);
    pvVar6 = (void *)WindowsGetStringRawBuffer(param_5,0);
    plVar7 = FUN_180004878(local_198,pvVar6,puVar18);
    plVar8 = FUN_180004878(local_1b8,L"</text><text>",puVar18);
    pvVar6 = (void *)WindowsGetStringRawBuffer(param_4,0);
    plVar9 = FUN_180004878(local_1d8,pvVar6,puVar18);
    plVar10 = FUN_180004878(local_1f8,L"\"></image><text>",puVar18);
    pvVar6 = (void *)WindowsGetStringRawBuffer(uVar2,0);
    plVar11 = FUN_180004878(local_218,pvVar6,puVar18);
    local_140 = FUN_180004878(local_238,L"\" alt=\"",puVar18);
    pvVar6 = (void *)WindowsGetStringRawBuffer(param_1,0);
    plVar12 = FUN_180004878(local_258,pvVar6,puVar18);
    if (0x7ffffffffffffffeU - local_e0 < 0xf) goto LAB_180006272;
    FUN_180008bf4(local_340);
    pwVar16 = (wchar_t *)0x6a;
    if (uStack_328 - local_330 < 0x6a) {
      ppppuVar13 = (undefined8 ****)
                   FUN_1800042bc(local_340,0x6a,puVar18,
                                 L"\" activationType=\"protocol\"><visual><binding template=\"ToastGeneric\"><image placement=\"hero\" src=\"file:///"
                                 ,0x6a);
    }
    else {
      lVar5 = local_330 + 0x6a;
      ppppuVar13 = local_340;
      if (7 < uStack_328) {
        ppppuVar13 = (undefined8 ****)local_340[0];
      }
      lVar14 = local_330 * 2;
      pwVar16 = 
      L"\" activationType=\"protocol\"><visual><binding template=\"ToastGeneric\"><image placement=\"hero\" src=\"file:///"
      ;
      local_330 = lVar5;
      memmove((void *)((longlong)ppppuVar13 + lVar14),
              L"\" activationType=\"protocol\"><visual><binding template=\"ToastGeneric\"><image placement=\"hero\" src=\"file:///"
              ,0xd4);
      *(undefined2 *)((longlong)ppppuVar13 + lVar5 * 2) = 0;
      ppppuVar13 = local_340;
    }
    local_110 = *ppppuVar13;
    ppuStack_108 = ppppuVar13[1];
    local_100 = ppppuVar13[2];
    ppuStack_f8 = ppppuVar13[3];
    ppppuVar13[2] = (undefined8 ***)0x0;
    ppppuVar13[3] = (undefined8 ***)0x7;
    *(undefined2 *)ppppuVar13 = 0;
    FUN_1800089f0(local_318,pwVar16,&local_110,plVar12);
    FUN_1800089f0(local_278,pwVar16,local_318,local_140);
    FUN_1800089f0(local_298,pwVar16,local_278,plVar11);
    FUN_1800089f0(local_2b8,pwVar16,local_298,plVar10);
    FUN_1800089f0(local_2d8,pwVar16,local_2b8,plVar9);
    FUN_1800089f0(local_2f8,pwVar16,local_2d8,plVar8);
    FUN_1800089f0(&local_130,pwVar16,local_2f8,plVar7);
    FUN_1800089f0(local_d0,pwVar16,&local_130,plVar4);
    FUN_1800015f0(&local_130);
    FUN_1800015f0(local_2f8);
    FUN_1800015f0(local_2d8);
    FUN_1800015f0(local_2b8);
    FUN_1800015f0(local_298);
    FUN_1800015f0(local_278);
    FUN_1800015f0(local_318);
    FUN_1800015f0((longlong *)&local_110);
    FUN_1800015f0((longlong *)local_340);
    FUN_1800015f0(local_258);
    FUN_1800015f0(local_238);
    FUN_1800015f0(local_218);
    FUN_1800015f0(local_1f8);
    FUN_1800015f0(local_1d8);
    FUN_1800015f0(local_1b8);
    FUN_1800015f0(local_198);
    FUN_1800015f0(local_178);
    lVar5 = FUN_180006e38();
    if (lVar5 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
    }
    local_140 = (longlong *)0x0;
    if ((lVar5 != 0) &&
       (iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5,&DAT_180017dc8,&local_140),
       iVar3 < 0)) goto LAB_180006278;
    plVar4 = local_140;
    ppppwVar17 = local_d0;
    if (7 < local_b8) {
      ppppwVar17 = (wchar_t ****)local_d0[0];
    }
    pvVar6 = FUN_180001a50(local_318,(wchar_t *)ppppwVar17);
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)
                      (plVar4,*(undefined8 *)((longlong)pvVar6 + 0x18));
    if (iVar3 < 0) goto LAB_180006280;
    WindowsDeleteString(local_300);
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
    local_130 = 0x47500e487ab93c52;
    local_128 = 0x411a9dba;
    local_124 = 0x47189813;
    local_140 = (longlong *)0x0;
    iVar3 = GetActivationFactoryByPCWSTR
                      (L"Windows.UI.Notifications.ToastNotificationManager",(Guid *)&local_130,
                       &local_140);
    if (iVar3 < 0) goto LAB_180006288;
    lVar14 = FUN_18000176c(local_140);
    if (lVar14 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar14);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar14);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar14);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar14);
    }
    if (local_140 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar14);
    if (-1 < iVar3) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar14);
      local_110 = (undefined8 ***)0x407cd40dd6f5f569;
      ppuStack_108 = (undefined8 ***)0x14fd2cb4ca888989;
      local_140 = (longlong *)0x0;
      iVar3 = GetActivationFactoryByPCWSTR
                        (L"Windows.UI.Notifications.ToastNotificationManager",(Guid *)&local_110,
                         &local_140);
      if (iVar3 < 0) goto LAB_180006298;
      plVar4 = (longlong *)FUN_18000176c(local_140);
      if (plVar4 != (longlong *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
      }
      if (local_140 != (longlong *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)();
      }
      plVar7 = plVar4;
      uVar15 = FUN_18000176c(plVar4);
      local_130 = 0;
      lVar14 = FUN_180006f8c(plVar7,lVar5);
      local_130 = lVar14;
      iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(uVar15,lVar14);
      if (-1 < iVar3) {
        if (lVar14 != 0) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar14);
        }
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(uVar15);
        if (plVar4 != (longlong *)0x0) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
        }
        if (lVar5 != 0) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
        }
        FUN_1800015f0((longlong *)local_d0);
        WindowsDeleteString(uVar2);
        FUN_1800015f0(local_f0);
        FUN_1800012bc(local_a8);
        FUN_18000c7f0(local_58 ^ (ulonglong)auStackY_398);
        return;
      }
      iVar3 = FUN_180001ad4(iVar3);
      goto LAB_18000625a;
    }
  }
  iVar3 = FUN_180001ad4(iVar3);
LAB_180006298:
  FUN_180001ad4(iVar3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800062a0 FUN_1800062a0 */

void FUN_1800062a0(longlong param_1,longlong *param_2,size_t param_3)

{
  longlong *plVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined1 auStack_e8 [48];
  undefined8 *local_b8 [2];
  code *local_a8;
  ulonglong uStack_a0;
  code *local_98;
  undefined4 uStack_90;
  uint uStack_8c;
  longlong *local_88;
  longlong *local_80;
  wchar_t local_78 [40];
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStack_e8;
  FUN_1800011a0(local_78,L"ScreenSketchAppService::ShowToastBackgroundTask::Run",param_3,0x67);
  local_b8[0] = (undefined8 *)Platform::Details::Heap::Allocate(0x18,0x130);
  local_98 = FUN_180007920;
  uStack_90 = 0;
  uStack_a0 = (ulonglong)uStack_8c << 0x20;
  local_a8 = FUN_180007920;
  puVar3 = FUN_1800083dc(local_b8[0],param_1,&local_a8);
  local_80 = (longlong *)0x0;
  local_b8[0] = puVar3;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_2,puVar3,&local_80);
  if (-1 < iVar2) {
    if (puVar3 != (undefined8 *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar3);
    }
    puVar4 = (undefined8 *)FUN_180008244(param_2);
    puVar3 = *(undefined8 **)(param_1 + 0x28);
    local_b8[0] = puVar4;
    if (puVar3 != puVar4) {
      if (puVar4 != (undefined8 *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar4);
        puVar3 = *(undefined8 **)(param_1 + 0x28);
      }
      if (puVar3 != (undefined8 *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)();
      }
      *(undefined8 **)(param_1 + 0x28) = puVar4;
    }
    if (puVar4 != (undefined8 *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar4);
    }
    puVar3 = (undefined8 *)FUN_1800081bc(param_2);
    local_80 = (longlong *)0x0;
    local_b8[0] = puVar3;
    if ((puVar3 != (undefined8 *)0x0) &&
       (iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar3,&DAT_180017da8,&local_80),
       iVar2 < 0)) goto LAB_180006576;
    plVar1 = local_80;
    local_88 = local_80;
    if (local_80 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_80);
      local_88 = plVar1;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar1);
    }
    if (puVar3 != (undefined8 *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar3);
    }
    puVar4 = (undefined8 *)FUN_180008134(plVar1);
    puVar3 = *(undefined8 **)(param_1 + 0x30);
    local_b8[0] = puVar4;
    if (puVar4 != puVar3) {
      if (puVar4 != (undefined8 *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar4);
        puVar3 = *(undefined8 **)(param_1 + 0x30);
      }
      if (puVar3 != (undefined8 *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar3);
      }
      *(undefined8 **)(param_1 + 0x30) = puVar4;
      puVar3 = puVar4;
    }
    if (puVar4 != (undefined8 *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar4);
      puVar3 = *(undefined8 **)(param_1 + 0x30);
    }
    local_98 = (code *)Platform::Details::Heap::Allocate(0x18,0x130);
    uStack_a0 = uStack_a0 & 0xffffffff00000000;
    local_a8 = FUN_180006580;
    pcVar5 = (code *)FUN_180008624((undefined8 *)local_98,param_1,&local_a8);
    local_b8[0] = (undefined8 *)0x0;
    local_98 = pcVar5;
    iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar3,pcVar5,local_b8);
    if (-1 < iVar2) {
      if (pcVar5 != (code *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(pcVar5);
      }
      if (plVar1 != (longlong *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar1);
      }
      FUN_1800012bc(local_78);
      FUN_18000c7f0(local_28 ^ (ulonglong)auStack_e8);
      return;
    }
    iVar2 = FUN_180001ad4(iVar2);
  }
  iVar2 = FUN_180001ad4(iVar2);
LAB_180006576:
  FUN_180001ad4(iVar2);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}


/* Function 180006580 FUN_180006580 */

void FUN_180006580(longlong *param_1,longlong *param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  longlong local_18;
  longlong local_10;
  
  FUN_1800065e0(param_1,&local_18,param_2,param_3);
  if (local_10 != 0) {
    LOCK();
    piVar1 = (int *)(local_10 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_10);
      LOCK();
      piVar1 = (int *)(local_10 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_10);
      }
    }
  }
  return;
}


/* Function 1800065e0 FUN_1800065e0 */

longlong * FUN_1800065e0(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  void *pvVar1;
  int local_res10 [2];
  
  pvVar1 = operator_new(0xa89);
  local_res10[0] = 0;
  FUN_18000d4ec(local_res10,(undefined8 *)((longlong)pvVar1 + 0x10),param_2,param_3,param_4,param_1)
  ;
  return param_2;
}


/* Function 180006658 FUN_180006658 */

longlong * FUN_180006658(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = *param_2;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
  }
  *param_1 = lVar1;
  return param_1;
}


/* Function 180006690 FUN_180006690 */

undefined8 * FUN_180006690(undefined8 *param_1,longlong *param_2)

{
  if (param_2 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_2);
  }
  *param_1 = param_2;
  return param_1;
}


/* Function 1800066d0 FUN_1800066d0 */

undefined8 FUN_1800066d0(longlong *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  *param_2 = 0;
  uVar1 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  *param_2 = uVar1;
  return 0;
}


/* Function 180006710 FUN_180006710 */
/* FAILED: Exception while decompiling 180006710: Decompiler process died
 */

/* Function 180006850 abi_AddRef */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __cdecl Platform::Array<class Platform::String ^
   __ptr64,1>::[Platform::Object]::__abi_AddRef(void) __ptr64
    public: virtual unsigned long __cdecl Platform::WriteOnlyArray<class Platform::String ^
   __ptr64,1>::[Platform::Object]::__abi_AddRef(void) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int abi_AddRef(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((*(longlong *)(param_1 + 0x10) == 0) || (*(int *)(*(longlong *)(param_1 + 0x10) + 0xc) < 0)) {
    iVar2 = -1;
  }
  else {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x10) + 0xc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


/* Function 180006880 FUN_180006880 */

ulong FUN_180006880(longlong param_1)

{
  ControlBlock *pCVar1;
  int iVar2;
  ControlBlock *this;
  ulong uVar3;
  
  uVar3 = __abi_FTMWeakRefData::Decrement((__abi_FTMWeakRefData *)(param_1 + 0x10));
  if (uVar3 == 0) {
    this = *(ControlBlock **)(param_1 + 0x10);
    Platform::Details::ControlBlock::ReleaseTarget(this);
    LOCK();
    pCVar1 = this + 8;
    iVar2 = *(int *)pCVar1;
    *(int *)pCVar1 = *(int *)pCVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (this[0x19] == (ControlBlock)0x0) {
        Platform::Details::Heap::Free(this);
      }
      else {
        Platform::Details::Heap::AlignedFree(this);
      }
    }
  }
  return uVar3;
}


/* Function 1800068e0 FUN_1800068e0 */

void FUN_1800068e0(undefined8 param_1,ulong *param_2,Guid **param_3)

{
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_28 = 0x35;
  local_20 = 0xc0;
  local_1c = 0x46000000;
  GetIidsFn(1,param_2,(__s_GUID *)&local_28,param_3);
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
  return;
}


/* Function 180006930 FUN_180006930 */

void FUN_180006930(undefined8 param_1,undefined8 param_2)

{
  WindowsCreateString(L"ScreenSketchAppService.__ShowToastBackgroundTaskActivationFactory",0x41,
                      param_2);
  return;
}


/* Function 180006950 FUN_180006950 */

undefined8 FUN_180006950(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0;
}


/* Function 180006960 FUN_180006960 */

void FUN_180006960(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)Platform::Details::Heap::Allocate(0x38,0x50);
  FUN_1800057a8(puVar1);
  return;
}


/* Function 180006990 FUN_180006990 */

undefined4
FUN_180006990(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)Platform::Details::Heap::Allocate(0x10,0x20);
  puVar2 = FUN_180005830(puVar2);
  uVar1 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar2 + 1,param_3,param_4);
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar2);
  return uVar1;
}


/* Function 180006a10 FUN_180006a10 */

wchar_t * FUN_180006a10(void)

{
  return L"ScreenSketchAppService.ShowToastBackgroundTask";
}


/* Function 180006a18 FUN_180006a18 */

undefined8 FUN_180006a18(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_1 + 0x48) != '\0') {
    __abi_WinRTraiseObjectDisposedException();
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return uVar3;
  }
  *param_2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x38);
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
  }
  *param_2 = lVar1;
  return 0;
}


/* Function 180006aa0 FUN_180006aa0 */

undefined8 FUN_180006aa0(longlong param_1,longlong *param_2,size_t param_3)

{
  if (*(char *)(param_1 + 0x48) != '\0') {
    __abi_WinRTraiseObjectDisposedException();
  }
  FUN_1800062a0(param_1,param_2,param_3);
  return 0;
}


/* Function 180006ad0 FUN_180006ad0 */

undefined8 FUN_180006ad0(ulonglong param_1,int *param_2,ulonglong *param_3)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (*param_2 == 0) {
    if ((param_2[1] == DAT_180016adc) && (iVar2 = DAT_180016ae4, param_2[2] == DAT_180016ae0))
    goto LAB_180006aff;
LAB_180006b04:
    plVar1 = (longlong *)(param_1 + 0x38);
    if (((*(longlong *)(param_1 + 0x40) == 0) || (*param_2 != -0x6b15d46c)) ||
       ((param_2[1] != DAT_180016acc ||
        ((param_2[2] != DAT_180016ad0 || (param_2[3] != DAT_180016ad4)))))) {
      if (*param_2 == 0x38) {
        if (((param_2[1] != DAT_180016a9c) || (param_2[2] != DAT_180016aa0)) ||
           (param_2[3] != DAT_180016aa4)) goto LAB_180006c5c;
        uVar4 = param_1 + 0x18;
      }
      else {
        if (((*param_2 != 0x7d13d534) || (param_2[1] != DAT_180017d64)) ||
           ((param_2[2] != DAT_180017d68 || (param_2[3] != DAT_180017d6c)))) {
LAB_180006c5c:
          if ((*(longlong *)(param_1 + 0x40) != 0) &&
             (iVar2 = FUN_180001970((longlong *)
                                    (-(ulonglong)(*(longlong *)(param_1 + 0x40) != 0) &
                                    (ulonglong)plVar1),param_2,param_3), iVar2 == 0)) {
            return 0;
          }
          return 0x80004002;
        }
        uVar4 = param_1 + 8;
      }
      *param_3 = -(ulonglong)(param_1 != 0) & uVar4;
      if (*plVar1 == 0) {
        return 0;
      }
      if (*(int *)(*plVar1 + 0xc) < 0) {
        return 0;
      }
      lVar3 = *plVar1;
      goto LAB_180006c56;
    }
  }
  else {
    if (*param_2 != -0x50791d20) {
      if (((*param_2 == -0x39a27663) && (param_2[1] == DAT_180017e34)) &&
         (iVar2 = DAT_180017e3c, param_2[2] == DAT_180017e38)) goto LAB_180006aff;
      goto LAB_180006b04;
    }
    if ((param_2[1] != DAT_180016aac) || (iVar2 = DAT_180016ab4, param_2[2] != DAT_180016ab0))
    goto LAB_180006b04;
LAB_180006aff:
    if (param_2[3] != iVar2) goto LAB_180006b04;
  }
  *param_3 = param_1;
  if (*(longlong *)(param_1 + 0x38) == 0) {
    return 0;
  }
  if (*(int *)(*(longlong *)(param_1 + 0x38) + 0xc) < 0) {
    return 0;
  }
  lVar3 = *(longlong *)(param_1 + 0x38);
LAB_180006c56:
  LOCK();
  *(int *)(lVar3 + 0xc) = *(int *)(lVar3 + 0xc) + 1;
  UNLOCK();
  return 0;
}


/* Function 180006c90 __abi_AddRef */

/* Library Function - Single Match
    public: virtual unsigned long __cdecl Platform::WriteOnlyArray<class Platform::String ^
   __ptr64,1>::[Platform::Object]::__abi_AddRef(void) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulong __thiscall
Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_AddRef
          (_Platform__Object_ *this)

{
  int *piVar1;
  int iVar2;
  ulong uVar3;
  
  if ((*(longlong *)(this + 0x38) == 0) || (*(int *)(*(longlong *)(this + 0x38) + 0xc) < 0)) {
    uVar3 = 0xffffffff;
  }
  else {
    LOCK();
    piVar1 = (int *)(*(longlong *)(this + 0x38) + 0xc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar3 = iVar2 + 1;
  }
  return uVar3;
}


/* Function 180006cc0 FUN_180006cc0 */

ulong FUN_180006cc0(longlong param_1)

{
  ControlBlock *pCVar1;
  int iVar2;
  ControlBlock *this;
  ulong uVar3;
  
  uVar3 = __abi_FTMWeakRefData::Decrement((__abi_FTMWeakRefData *)(param_1 + 0x38));
  if (uVar3 == 0) {
    if (*(longlong *)(param_1 + 0x30) != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    if (*(longlong *)(param_1 + 0x28) != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
    this = *(ControlBlock **)(param_1 + 0x38);
    Platform::Details::ControlBlock::ReleaseTarget(this);
    LOCK();
    pCVar1 = this + 8;
    iVar2 = *(int *)pCVar1;
    *(int *)pCVar1 = *(int *)pCVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (this[0x19] == (ControlBlock)0x0) {
        Platform::Details::Heap::Free(this);
      }
      else {
        Platform::Details::Heap::AlignedFree(this);
      }
    }
  }
  return uVar3;
}


/* Function 180006d60 __abi_GetIids */

/* Library Function - Single Match
    public: virtual long __cdecl Platform::WriteOnlyArray<class Platform::String ^
   __ptr64,1>::[Platform::Object]::__abi_GetIids(unsigned long * __ptr64,class Platform::Guid *
   __ptr64 * __ptr64) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

long __thiscall
Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_GetIids
          (_Platform__Object_ *this,ulong *param_1,Guid **param_2)

{
  long lVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_68;
  local_48 = 0xc65d899d;
  local_44 = 0x3675658a;
  local_40 = 0xf10bbf97;
  local_3c = 0x9e1ba40d;
  local_38 = 0x7d13d534;
  local_34 = 0x43cefd12;
  local_30 = 0x1fea228c;
  local_2c = 0xdf063cf1;
  local_28 = 0x38;
  local_20 = 0xc0;
  local_1c = 0x46000000;
  GetIidsFn(3,param_1,(__s_GUID *)&local_48,param_2);
  lVar1 = FUN_18000c7f0(local_18 ^ (ulonglong)auStack_68);
  return lVar1;
}


/* Function 180006df0 FUN_180006df0 */

void FUN_180006df0(undefined8 param_1,undefined8 param_2)

{
  WindowsCreateString(L"ScreenSketchAppService.ShowToastBackgroundTask",0x2e,param_2);
  return;
}


/* Function 180006e04 GetWeakReference */

/* Library Function - Single Match
    public: virtual struct Platform::Details::IWeakReference ^ __ptr64 __cdecl
   Platform::WriteOnlyArray<class Platform::String ^
   __ptr64,1>::[Platform::Details::IWeakReferenceSource]::GetWeakReference(void) __ptr64
   
   Library: Visual Studio 2019 Release */

IWeakReference * __thiscall
Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::
[Platform::Details::IWeakReferenceSource]::GetWeakReference
          (_Platform__Details__IWeakReferenceSource_ *this)

{
  IWeakReference *pIVar1;
  
  pIVar1 = *(IWeakReference **)(this + 0x38);
  if (pIVar1 != (IWeakReference *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(pIVar1);
  }
  return pIVar1;
}


/* Function 180006e38 FUN_180006e38 */

void FUN_180006e38(void)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_68 [32];
  longlong local_48;
  longlong local_40;
  longlong *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_68;
  local_28 = 0x35;
  local_20 = 0xc0;
  local_1c = 0x46000000;
  local_38 = (longlong *)0x0;
  lVar2 = GetActivationFactoryByPCWSTR
                    (L"Windows.Data.Xml.Dom.XmlDocument",(Guid *)&local_28,&local_38);
  if (-1 < lVar2) {
    lVar4 = FUN_18000176c(local_38);
    local_30 = 0;
    lVar5 = 0;
    local_40 = lVar4;
    if ((lVar4 != 0) &&
       (iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4,&DAT_180017d50,&local_30),
       lVar5 = 0, iVar3 == 0)) {
      lVar5 = local_30;
    }
    local_48 = lVar5;
    if (lVar5 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      local_48 = lVar5;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
    }
    if (lVar4 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
    }
    if (lVar5 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
    }
    if (local_38 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    FUN_18000c7f0(local_18 ^ (ulonglong)auStack_68);
    return;
  }
  FUN_180001ad4(lVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180006f8c FUN_180006f8c */

void FUN_180006f8c(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_58;
  local_28 = 0x4124b20;
  local_24 = 0x422982c6;
  local_20 = 0x9efd09b1;
  local_1c = 0x532b66d4;
  local_30 = (longlong *)0x0;
  lVar2 = GetActivationFactoryByPCWSTR
                    (L"Windows.UI.Notifications.ToastNotification",(Guid *)&local_28,&local_30);
  if (-1 < lVar2) {
    FUN_180001654(local_30,param_2);
    local_38 = 0;
    if (local_30 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    FUN_18000c7f0(local_18 ^ (ulonglong)auStack_58);
    return;
  }
  FUN_180001ad4(lVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180007040 FUN_180007040 */

undefined8 FUN_180007040(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((undefined **)*param_1 == &PTR_FUN_18001e4f8) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  else {
    iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (iVar2 < 0) {
      FUN_180001ad4(iVar2);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  return 0;
}


/* Function 1800070a0 FUN_1800070a0 */

undefined8 FUN_1800070a0(longlong param_1,int *param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*param_2 == 0) {
    if ((param_2[1] == DAT_180016adc) && (iVar2 = DAT_180016ae4, param_2[2] == DAT_180016ae0)) {
LAB_1800070d4:
      if (param_2[3] == iVar2) goto LAB_180007134;
    }
  }
  else if (((*param_2 == -0x593b4540) && (param_2[1] == DAT_180017d44)) &&
          (iVar2 = DAT_180017d4c, param_2[2] == DAT_180017d48)) goto LAB_1800070d4;
  if ((((*(longlong *)(param_1 + 0x20) == 0) || (*param_2 != -0x6b15d46c)) ||
      ((param_2[1] != DAT_180016acc ||
       ((param_2[2] != DAT_180016ad0 || (param_2[3] != DAT_180016ad4)))))) &&
     ((*param_2 != -0x593b4540 ||
      (((param_2[1] != DAT_180017d44 || (param_2[2] != DAT_180017d48)) ||
       (param_2[3] != DAT_180017d4c)))))) {
    if ((*(longlong *)(param_1 + 0x20) != 0) &&
       (iVar2 = FUN_180001970((longlong *)
                              (-(ulonglong)(*(longlong *)(param_1 + 0x20) != 0) & param_1 + 0x18U),
                              param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    return 0x80004002;
  }
LAB_180007134:
  *param_3 = param_1;
  if ((*(longlong *)(param_1 + 0x18) != 0) && (-1 < *(int *)(*(longlong *)(param_1 + 0x18) + 0xc)))
  {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 0xc);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  return 0;
}


/* Function 1800071c0 abi_AddRef */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __cdecl Platform::Array<class Platform::String ^
   __ptr64,1>::[Platform::Object]::__abi_AddRef(void) __ptr64
    public: virtual unsigned long __cdecl Platform::WriteOnlyArray<class Platform::String ^
   __ptr64,1>::[Platform::Object]::__abi_AddRef(void) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int abi_AddRef(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((*(longlong *)(param_1 + 0x18) == 0) || (*(int *)(*(longlong *)(param_1 + 0x18) + 0xc) < 0)) {
    iVar2 = -1;
  }
  else {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 0xc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


/* Function 1800071f0 FUN_1800071f0 */

ulong FUN_1800071f0(longlong param_1)

{
  ControlBlock *pCVar1;
  int iVar2;
  void *pvVar3;
  ControlBlock *this;
  ulong uVar4;
  
  uVar4 = __abi_FTMWeakRefData::Decrement((__abi_FTMWeakRefData *)(param_1 + 0x18));
  if (uVar4 == 0) {
    pvVar3 = *(void **)(param_1 + 0x128);
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(pvVar3,0);
    if (pvVar3 != (void *)(param_1 + 0x28)) {
      Platform::Details::Heap::Free(pvVar3);
    }
    this = *(ControlBlock **)(param_1 + 0x18);
    Platform::Details::ControlBlock::ReleaseTarget(this);
    LOCK();
    pCVar1 = this + 8;
    iVar2 = *(int *)pCVar1;
    *(int *)pCVar1 = *(int *)pCVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (this[0x19] == (ControlBlock)0x0) {
        Platform::Details::Heap::Free(this);
      }
      else {
        Platform::Details::Heap::AlignedFree(this);
      }
    }
  }
  return uVar4;
}


/* Function 180007290 FUN_180007290 */

void FUN_180007290(undefined8 param_1,ulong *param_2,Guid **param_3)

{
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_28 = 0xa6c4bac0;
  local_24 = 0x4c5751f8;
  local_20 = 0x6d153fac;
  local_1c = 0x4f0c68d1;
  GetIidsFn(1,param_2,(__s_GUID *)&local_28,param_3);
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
  return;
}


/* Function 1800072e8 FUN_1800072e8 */

void FUN_1800072e8(undefined8 param_1,undefined8 param_2)

{
  WindowsCreateString(L"Windows.ApplicationModel.Background.BackgroundTaskCanceledEventHandler",0x46
                      ,param_2);
  return;
}


/* Function 180007300 FUN_180007300 */

void FUN_180007300(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((undefined **)*param_1 == &PTR_FUN_18001e4f8) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  else {
    iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (iVar2 < 0) {
      FUN_180001ad4(iVar2);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  return;
}


/* Function 180007350 FUN_180007350 */

undefined8 FUN_180007350(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((undefined **)*param_1 == &PTR_FUN_18001e4d0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  else {
    iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (iVar2 < 0) {
      FUN_180001ad4(iVar2);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  return 0;
}


/* Function 1800073b0 FUN_1800073b0 */

undefined8 FUN_1800073b0(longlong param_1,int *param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*param_2 == 0) {
    if ((param_2[1] == DAT_180016adc) && (iVar2 = DAT_180016ae4, param_2[2] == DAT_180016ae0)) {
LAB_1800073df:
      if (param_2[3] == iVar2) goto LAB_180007443;
    }
  }
  else if (((*param_2 == 0x18c67d61) && (param_2[1] == DAT_180017d34)) &&
          (iVar2 = DAT_180017d3c, param_2[2] == DAT_180017d38)) goto LAB_1800073df;
  if ((((*(longlong *)(param_1 + 0x20) == 0) || (*param_2 != -0x6b15d46c)) ||
      ((param_2[1] != DAT_180016acc ||
       ((param_2[2] != DAT_180016ad0 || (param_2[3] != DAT_180016ad4)))))) &&
     ((*param_2 != -0x621e3acc ||
      (((param_2[1] != DAT_180017dbc || (param_2[2] != DAT_180017dc0)) ||
       (param_2[3] != DAT_180017dc4)))))) {
    if ((*(longlong *)(param_1 + 0x20) != 0) &&
       (iVar2 = FUN_180001970((longlong *)
                              (-(ulonglong)(*(longlong *)(param_1 + 0x20) != 0) & param_1 + 0x18U),
                              param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    return 0x80004002;
  }
LAB_180007443:
  *param_3 = param_1;
  if ((*(longlong *)(param_1 + 0x18) != 0) && (-1 < *(int *)(*(longlong *)(param_1 + 0x18) + 0xc)))
  {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 0xc);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  return 0;
}


/* Function 1800074cc FUN_1800074cc */

void FUN_1800074cc(undefined8 param_1,ulong *param_2,Guid **param_3)

{
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_28 = 0x9de1c534;
  local_24 = 0x11e06ae1;
  local_20 = 0xa918e184;
  local_1c = 0x3fc5bc05;
  GetIidsFn(1,param_2,(__s_GUID *)&local_28,param_3);
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
  return;
}


/* Function 180007524 FUN_180007524 */

void FUN_180007524(undefined8 param_1,undefined8 param_2)

{
  WindowsCreateString(L"Windows.Foundation.TypedEventHandler`2<Windows.ApplicationModel.AppService.AppServiceConnection, Windows.ApplicationModel.AppService.AppServiceRequestReceivedEventArgs>"
                      ,0xa8,param_2);
  return;
}


/* Function 180007540 FUN_180007540 */

void FUN_180007540(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((undefined **)*param_1 == &PTR_FUN_18001e4d0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  else {
    iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (iVar2 < 0) {
      FUN_180001ad4(iVar2);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  return;
}


/* Function 180007584 FUN_180007584 */

void FUN_180007584(void)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_68 [32];
  longlong local_48;
  longlong local_40;
  longlong *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_68;
  local_28 = 0x35;
  local_20 = 0xc0;
  local_1c = 0x46000000;
  local_38 = (longlong *)0x0;
  lVar2 = GetActivationFactoryByPCWSTR
                    (L"Windows.Foundation.Collections.ValueSet",(Guid *)&local_28,&local_38);
  if (-1 < lVar2) {
    lVar4 = FUN_18000176c(local_38);
    local_30 = 0;
    lVar5 = 0;
    local_40 = lVar4;
    if ((lVar4 != 0) &&
       (iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4,&DAT_180017cc8,&local_30),
       lVar5 = 0, iVar3 == 0)) {
      lVar5 = local_30;
    }
    local_48 = lVar5;
    if (lVar5 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      local_48 = lVar5;
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
    }
    if (lVar4 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
    }
    if (lVar5 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
    }
    if (local_38 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    FUN_18000c7f0(local_18 ^ (ulonglong)auStack_68);
    return;
  }
  FUN_180001ad4(lVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800076d8 FUN_1800076d8 */

void FUN_1800076d8(longlong *param_1)

{
  code *pcVar1;
  longlong *plVar2;
  int iVar3;
  undefined1 auStack_58 [32];
  longlong *local_38;
  Exception *local_30;
  longlong *local_28;
  int local_20 [2];
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_58;
  local_28 = (longlong *)0x0;
  if ((*param_1 == 0) ||
     (iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,&DAT_180017cb8,&local_28),
     -1 < iVar3)) {
    plVar2 = local_28;
    local_20[0] = 0;
    local_38 = local_28;
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_28,local_20);
    if (-1 < iVar3) {
      if (local_20[0] == 2) {
        local_30 = Platform::Exception::CreateException(-0x7fffbffc);
        local_28 = FUN_180001c50((longlong *)local_30);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_28,(ThrowInfo *)&DAT_18001aff0);
      }
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar2);
      local_20[0] = 0;
      iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,local_20);
      if (iVar3 < 0) {
        FUN_180001ad4(iVar3);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      FUN_18000c7f0(local_18 ^ (ulonglong)auStack_58);
      return;
    }
  }
  else {
    iVar3 = FUN_180001ad4(iVar3);
  }
  FUN_180001ad4(iVar3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800077e0 FUN_1800077e0 */

undefined8 *
FUN_1800077e0(undefined8 *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  if (param_2 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_2);
  }
  *param_1 = param_2;
  if (param_3 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_3);
  }
  param_1[1] = param_3;
  if (param_4 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_4);
  }
  param_1[2] = param_4;
  return param_1;
}


/* Function 180007868 FUN_180007868 */

longlong * FUN_180007868(longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong local_78;
  longlong lStack_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 local_40;
  undefined1 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined2 local_10;
  
  plVar1 = (longlong *)FUN_18000acc4();
  local_60 = plVar1[1];
  if (local_60 != 0) {
    LOCK();
    *(int *)(local_60 + 8) = *(int *)(local_60 + 8) + 1;
    UNLOCK();
    local_60 = plVar1[1];
  }
  local_68 = *plVar1;
  lStack_70 = param_1[1];
  local_50 = 0;
  local_48 = 1;
  local_40 = 0;
  local_18 = 0;
  local_30 = 0;
  local_38 = 0;
  local_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (lStack_70 != 0) {
    LOCK();
    *(int *)(lStack_70 + 8) = *(int *)(lStack_70 + 8) + 1;
    UNLOCK();
    lStack_70 = param_1[1];
  }
  local_78 = *param_1;
  local_58 = local_68;
  FUN_18000c138(param_2,&local_78,&local_68,param_4);
  return param_2;
}


/* Function 180007920 FUN_180007920 */

void FUN_180007920(longlong param_1,undefined8 param_2,size_t param_3)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  undefined1 auStack_98 [32];
  longlong local_78;
  wchar_t local_68 [40];
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_98;
  FUN_1800011a0(local_68,L"ScreenSketchAppService::ShowToastBackgroundTask::OnCanceled",param_3,
                0x103);
  lVar1 = *(longlong *)(param_1 + 0x28);
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
    local_78 = lVar1;
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
    if (iVar3 < 0) {
      FUN_180001ad4(iVar3);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
    if (*(longlong *)(param_1 + 0x28) != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
  }
  if (*(longlong *)(param_1 + 0x30) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  FUN_1800012bc(local_68);
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_98);
  return;
}


/* Function 180007a08 FUN_180007a08 */

void FUN_180007a08(longlong *param_1)

{
  if (*param_1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return;
}


/* Function 180007a34 FUN_180007a34 */

void FUN_180007a34(longlong *param_1)

{
  if (*param_1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return;
}


/* Function 180007a54 FUN_180007a54 */

void FUN_180007a54(longlong *param_1)

{
  if (param_1[2] != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  if (param_1[1] != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  if (*param_1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return;
}


/* Function 180007aa8 FUN_180007aa8 */

void FUN_180007aa8(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 8);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      LOCK();
      piVar1 = (int *)(lVar3 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      }
    }
  }
  return;
}


/* Function 180007af8 FUN_180007af8 */

undefined8 *
FUN_180007af8(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)operator_new(0x98);
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined4 *)(puVar1 + 1) = 1;
  *(undefined4 *)((longlong)puVar1 + 0xc) = 1;
  *puVar1 = &PTR_FUN_18001e368;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  _Mtx_init_in_situ(puVar1 + 5,2);
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  *(undefined2 *)(puVar1 + 0x12) = 0;
  *param_1 = 0;
  param_1[1] = 0;
  *param_1 = puVar1 + 2;
  param_1[1] = puVar1;
  return param_1;
}


/* Function 180007b90 FUN_180007b90 */

undefined8 * FUN_180007b90(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* Function 180007b98 FUN_180007b98 */

void FUN_180007b98(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  
  uVar1 = *param_1;
  puVar4 = (undefined8 *)Platform::Details::Heap::Allocate(0x18,0x130);
  puVar4 = FUN_1800088ec(puVar4,param_2);
  iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(uVar1,puVar4);
  if (-1 < iVar3) {
    if (puVar4 != (undefined8 *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar4);
    }
    return;
  }
  FUN_180001ad4(iVar3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


/* Function 180007c10 FUN_180007c10 */

undefined8 FUN_180007c10(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((undefined **)*param_1 == &PTR_FUN_18001e340) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  else {
    iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (iVar2 < 0) {
      FUN_180001ad4(iVar2);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  return 0;
}


/* Function 180007c70 FUN_180007c70 */

undefined8 FUN_180007c70(longlong param_1,int *param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*param_2 == 0) {
    if ((param_2[1] == DAT_180016adc) && (iVar2 = DAT_180016ae4, param_2[2] == DAT_180016ae0)) {
LAB_180007c9f:
      if (param_2[3] == iVar2) goto LAB_180007d03;
    }
  }
  else if (((*param_2 == -0x47dbc7c3) && (param_2[1] == DAT_180017c6c)) &&
          (iVar2 = DAT_180017c74, param_2[2] == DAT_180017c70)) goto LAB_180007c9f;
  if ((((*(longlong *)(param_1 + 0x20) == 0) || (*param_2 != -0x6b15d46c)) ||
      ((param_2[1] != DAT_180016acc ||
       ((param_2[2] != DAT_180016ad0 || (param_2[3] != DAT_180016ad4)))))) &&
     ((*param_2 != -0x3230fd4 ||
      (((param_2[1] != DAT_180017c7c || (param_2[2] != DAT_180017c80)) ||
       (param_2[3] != DAT_180017c84)))))) {
    if ((*(longlong *)(param_1 + 0x20) != 0) &&
       (iVar2 = FUN_180001970((longlong *)
                              (-(ulonglong)(*(longlong *)(param_1 + 0x20) != 0) & param_1 + 0x18U),
                              param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    return 0x80004002;
  }
LAB_180007d03:
  *param_3 = param_1;
  if ((*(longlong *)(param_1 + 0x18) != 0) && (-1 < *(int *)(*(longlong *)(param_1 + 0x18) + 0xc)))
  {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 0xc);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  return 0;
}


/* Function 180007d8c FUN_180007d8c */

void FUN_180007d8c(undefined8 param_1,ulong *param_2,Guid **param_3)

{
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_28 = 0xfcdcf02c;
  local_24 = 0x4478e5d8;
  local_20 = 0x904d5a91;
  local_1c = 0xa5834bb7;
  GetIidsFn(1,param_2,(__s_GUID *)&local_28,param_3);
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
  return;
}


/* Function 180007de4 FUN_180007de4 */

void FUN_180007de4(undefined8 param_1,undefined8 param_2)

{
  WindowsCreateString(L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.ApplicationModel.AppService.AppServiceResponseStatus>"
                      ,0x71,param_2);
  return;
}


/* Function 180007e00 FUN_180007e00 */

void FUN_180007e00(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((undefined **)*param_1 == &PTR_FUN_18001e340) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  else {
    iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (iVar2 < 0) {
      FUN_180001ad4(iVar2);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  return;
}


/* Function 180007e44 FUN_180007e44 */

void FUN_180007e44(longlong *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_20 = 0;
  if ((*param_1 == 0) ||
     (iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,&DAT_180017cb8,&local_20),
     -1 < iVar3)) {
    uVar2 = local_20;
    local_18[0] = 0;
    local_28 = local_20;
    iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_20,local_18);
    if (-1 < iVar3) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(uVar2);
      FUN_18000c7f0(local_10 ^ (ulonglong)auStack_48);
      return;
    }
    iVar3 = FUN_180001ad4(iVar3);
  }
  FUN_180001ad4(iVar3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180007ef4 FUN_180007ef4 */

void FUN_180007ef4(longlong *param_1)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  __ExceptionPtrCreate(&local_18);
  __ExceptionPtrCurrentException(&local_18);
  FUN_180009484(param_1,&local_18);
  return;
}


/* Function 180007f30 FUN_180007f30 */

void FUN_180007f30(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong **pplVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  longlong *plVar7;
  undefined1 auStack_58 [32];
  longlong local_38;
  longlong *local_28;
  longlong *plStack_20;
  longlong *local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_58;
  lVar1 = *param_1;
  if ((*(char *)(lVar1 + 0x80) == '\0') && (*(char *)(lVar1 + 0x81) == '\0')) {
    local_28 = (longlong *)0x0;
    plStack_20 = (longlong *)0x0;
    local_18 = (longlong *)0x0;
    bVar5 = false;
    iVar6 = _Mtx_lock(lVar1 + 0x18);
    if (iVar6 != 0) {
      std::_Throw_C_error(iVar6);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    lVar2 = *param_1;
    if ((*(char *)(lVar2 + 0x80) == '\0') && (*(char *)(lVar2 + 0x81) == '\0')) {
      *(undefined1 *)(lVar2 + 0x68) = 0;
      *(undefined1 *)(*param_1 + 0x80) = 1;
      pplVar3 = (longlong **)*param_1;
      plVar7 = (longlong *)0x0;
      if (&local_28 != pplVar3) {
        plVar7 = *pplVar3;
        *pplVar3 = (longlong *)0x0;
        plStack_20 = pplVar3[1];
        pplVar3[1] = (longlong *)0x0;
        local_18 = pplVar3[2];
        pplVar3[2] = (longlong *)0x0;
        local_28 = plVar7;
      }
      bVar5 = true;
    }
    else {
      plVar7 = (longlong *)0x0;
    }
    _Mtx_unlock(lVar1 + 0x18);
    if (bVar5) {
      for (; plVar7 != plStack_20; plVar7 = plVar7 + 2) {
        lVar1 = *plVar7;
        if (*(int *)(*plVar7 + 8) == 2) {
          local_38 = lVar1 + 0x10;
          param_4 = 0;
          param_3 = 0;
          (*(code *)PTR__guard_dispatch_icall_1800165a8)
                    (lVar1,CONCAT71((int7)((ulonglong)local_38 >> 8),1));
        }
        else {
          FUN_18000bb78(lVar1,(ulonglong)
                              CONCAT31((int3)((uint)*(int *)(*plVar7 + 8) >> 8),
                                       *(undefined1 *)(*param_1 + 0x68)),param_3,param_4);
        }
      }
    }
    FUN_1800097d0((longlong *)&local_28);
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_58);
  return;
}


/* Function 180008084 FUN_180008084 */

undefined1 * FUN_180008084(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 0;
  return param_2;
}


/* Function 18000808c ReleaseDirectDraw */

/* Library Function - Single Match
    public: void __cdecl CLoadDirectDraw::ReleaseDirectDraw(void) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __thiscall CLoadDirectDraw::ReleaseDirectDraw(CLoadDirectDraw *this)

{
  if (*(longlong *)this != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    *(undefined8 *)this = 0;
  }
  return;
}


/* Function 1800080b4 FUN_1800080b4 */

void FUN_1800080b4(longlong *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_48 [32];
  longlong local_28;
  undefined1 local_20 [8];
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_28 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,param_2,&local_28);
  if (iVar2 < 0) {
    FUN_180001ad4(iVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if ((local_28 != 0) && (iVar2 = WindowsDuplicateString(local_28,local_20), iVar2 < 0)) {
    FUN_180001ad4(iVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  WindowsDeleteString(local_28);
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
  return;
}


/* Function 180008134 FUN_180008134 */

void FUN_180008134(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800081bc FUN_1800081bc */

void FUN_1800081bc(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180008244 FUN_180008244 */

void FUN_180008244(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800082cc FUN_1800082cc */

void FUN_1800082cc(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180008354 FUN_180008354 */

void FUN_180008354(longlong *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,param_2,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 1800083dc FUN_1800083dc */

undefined8 * FUN_1800083dc(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  Platform::Delegate::Delegate((Delegate *)(param_1 + 2));
  *param_1 = &PTR_FUN_18001e4f8;
  param_1[1] = &PTR_FUN_18001e300;
  param_1[2] = &PTR_FUN_18001e2d0;
  param_1[4] = 0xffffffffffffffff;
  if (DAT_18001eee0 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  puVar1 = param_1 + 5;
  param_1[0x25] = puVar1;
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = *param_3;
    uVar3 = param_3[1];
    *puVar1 = &PTR_FUN_18001e330;
    lVar4 = FUN_180008d6c((longlong *)(-(ulonglong)(param_2 != 0) & param_2 + 0x18U));
    if (lVar4 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
    }
    param_1[6] = lVar4;
    if (lVar4 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
    }
    param_1[7] = uVar2;
    param_1[8] = uVar3;
  }
  param_1[0x25] = puVar1;
  return param_1;
}


/* Function 1800084e0 FUN_1800084e0 */

void FUN_1800084e0(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_68 [32];
  DisconnectedException *local_48;
  longlong *local_40;
  longlong *local_38;
  ulonglong local_30;
  
  local_30 = DAT_18001e100 ^ (ulonglong)auStack_68;
  plVar4 = (longlong *)FUN_180008df4(*(longlong **)(param_1 + 8),&DAT_180017e30);
  local_40 = plVar4;
  local_38 = plVar4;
  if (plVar4 == (longlong *)0x0) {
    local_48 = (DisconnectedException *)Platform::Details::Heap::AllocateException(0x68,0x90);
    local_48 = (DisconnectedException *)
               Platform::DisconnectedException::DisconnectedException(local_48);
    local_38 = FUN_180001c50((longlong *)local_48);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_38,(ThrowInfo *)&DAT_18001af18);
  }
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
  local_38 = (longlong *)0x0;
  iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4,&DAT_180017e30,&local_38);
  plVar2 = local_38;
  if (-1 < iVar3) {
    local_48 = (DisconnectedException *)local_38;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)
              ((longlong)*(int *)(param_1 + 0x18) + (longlong)local_38,param_2,param_3);
    if (plVar2 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar2);
    }
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
    FUN_18000c7f0(local_30 ^ (ulonglong)auStack_68);
    return;
  }
  FUN_180001ad4(iVar3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180008624 FUN_180008624 */

undefined8 * FUN_180008624(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  Platform::Delegate::Delegate((Delegate *)(param_1 + 2));
  *param_1 = &PTR_FUN_18001e4d0;
  param_1[1] = &PTR_FUN_18001e290;
  param_1[2] = &PTR_FUN_18001e260;
  param_1[4] = 0xffffffffffffffff;
  if (DAT_18001eee0 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  puVar1 = param_1 + 5;
  param_1[0x25] = puVar1;
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = *param_3;
    uVar3 = param_3[1];
    *puVar1 = &PTR_FUN_18001e2c0;
    lVar4 = FUN_180008d6c((longlong *)(-(ulonglong)(param_2 != 0) & param_2 + 0x18U));
    if (lVar4 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
    }
    param_1[6] = lVar4;
    if (lVar4 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
    }
    param_1[7] = uVar2;
    param_1[8] = uVar3;
  }
  param_1[0x25] = puVar1;
  return param_1;
}


/* Function 180008730 FUN_180008730 */

void FUN_180008730(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_68 [32];
  DisconnectedException *local_48;
  longlong *local_40;
  longlong *local_38;
  ulonglong local_30;
  
  local_30 = DAT_18001e100 ^ (ulonglong)auStack_68;
  plVar4 = (longlong *)FUN_180008df4(*(longlong **)(param_1 + 8),&DAT_180017e30);
  local_40 = plVar4;
  local_38 = plVar4;
  if (plVar4 == (longlong *)0x0) {
    local_48 = (DisconnectedException *)Platform::Details::Heap::AllocateException(0x68,0x90);
    local_48 = (DisconnectedException *)
               Platform::DisconnectedException::DisconnectedException(local_48);
    local_38 = FUN_180001c50((longlong *)local_48);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_38,(ThrowInfo *)&DAT_18001af18);
  }
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
  local_38 = (longlong *)0x0;
  iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4,&DAT_180017e30,&local_38);
  plVar2 = local_38;
  if (-1 < iVar3) {
    local_48 = (DisconnectedException *)local_38;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)
              ((longlong)*(int *)(param_1 + 0x18) + (longlong)local_38,param_2,param_3);
    if (plVar2 != (longlong *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar2);
    }
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar4);
    FUN_18000c7f0(local_30 ^ (ulonglong)auStack_68);
    return;
  }
  FUN_180001ad4(iVar3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180008874 FUN_180008874 */

undefined8 * FUN_180008874(undefined8 *param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = *param_2;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
  }
  param_1[7] = 0;
  *param_1 = &PTR_FUN_18001e1c0;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
  }
  param_1[1] = lVar1;
  param_1[7] = param_1;
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
  }
  return param_1;
}


/* Function 1800088ec FUN_1800088ec */

undefined8 * FUN_1800088ec(undefined8 *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  Platform::Delegate::Delegate((Delegate *)(param_1 + 2));
  lVar2 = DAT_18001eee0;
  *param_1 = &PTR_FUN_18001e340;
  param_1[1] = &PTR_FUN_18001e230;
  param_1[2] = &PTR_FUN_18001e200;
  param_1[4] = 0;
  if (lVar2 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  puVar1 = param_1 + 5;
  param_1[0x25] = puVar1;
  if (puVar1 != (undefined8 *)0x0) {
    param_1[6] = param_2;
    *puVar1 = &PTR_FUN_18001e1f0;
  }
  param_1[0x25] = puVar1;
  return param_1;
}


/* Function 180008990 FUN_180008990 */

undefined8 * FUN_180008990(undefined8 *param_1,ulonglong param_2)

{
  if (param_1[1] != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  *param_1 = &PTR_FUN_18001e520;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 1800089e0 FUN_1800089e0 */

/* WARNING: Switch with 1 destination removed at 0x0001800089e7 */

void FUN_1800089e0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180012b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)**(undefined8 **)(param_1 + 8))();
  return;
}


/* Function 1800089f0 FUN_1800089f0 */

undefined8 *
FUN_1800089f0(undefined8 *param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  void *pvVar7;
  undefined8 *puVar8;
  void *pvVar9;
  ulonglong uVar10;
  size_t _Size;
  
  pvVar9 = (void *)0x0;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  uVar2 = param_3[2];
  uVar3 = param_4[2];
  uVar1 = uVar3 + uVar2;
  if ((param_3[3] - uVar2 < uVar3) || ((ulonglong)param_3[3] < (ulonglong)param_4[3])) {
    if (param_4[3] - uVar3 < uVar2) {
      if (0x7ffffffffffffffe - uVar2 < uVar3) {
        FUN_180001320();
        pcVar4 = (code *)swi(3);
        puVar8 = (undefined8 *)(*pcVar4)();
        return puVar8;
      }
      uVar6 = uVar1 | 7;
      uVar10 = 0x7ffffffffffffffe;
      if ((uVar6 < 0x7fffffffffffffff) && (uVar10 = uVar6, uVar6 < 10)) {
        uVar10 = 10;
      }
      uVar6 = uVar10 + 1;
      if (uVar10 == 0xffffffffffffffff) {
        uVar6 = 0xffffffffffffffff;
      }
      if (uVar6 < 0x8000000000000000) {
        uVar6 = uVar6 * 2;
        if (uVar6 < 0x1000) {
          if (uVar6 != 0) {
            pvVar9 = operator_new(uVar6);
          }
        }
        else {
          if (uVar6 + 0x27 <= uVar6) goto LAB_180008bee;
          pvVar7 = operator_new(uVar6 + 0x27);
          if (pvVar7 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          pvVar9 = (void *)((longlong)pvVar7 + 0x27U & 0xffffffffffffffe0);
          *(void **)((longlong)pvVar9 - 8) = pvVar7;
        }
        *param_1 = pvVar9;
        param_1[2] = uVar1;
        param_1[3] = uVar10;
        if (7 < (ulonglong)param_3[3]) {
          param_3 = (undefined8 *)*param_3;
        }
        memcpy(pvVar9,param_3,uVar2 * 2);
        if (7 < (ulonglong)param_4[3]) {
          param_4 = (undefined8 *)*param_4;
        }
        memcpy((void *)(uVar2 * 2 + (longlong)pvVar9),param_4,uVar3 * 2 + 2);
        return param_1;
      }
LAB_180008bee:
      FUN_180001488();
      pcVar4 = (code *)swi(3);
      puVar8 = (undefined8 *)(*pcVar4)();
      return puVar8;
    }
    uVar5 = param_4[1];
    _Size = uVar2 * 2;
    *param_1 = *param_4;
    param_1[1] = uVar5;
    uVar5 = param_4[3];
    param_1[2] = param_4[2];
    param_1[3] = uVar5;
    param_4[2] = 0;
    param_4[3] = 7;
    *(undefined2 *)param_4 = 0;
    pvVar9 = (void *)*param_1;
    memmove((void *)(_Size + (longlong)pvVar9),pvVar9,uVar3 * 2 + 2);
    if (7 < (ulonglong)param_3[3]) {
      param_3 = (undefined8 *)*param_3;
    }
  }
  else {
    uVar5 = param_3[1];
    *param_1 = *param_3;
    param_1[1] = uVar5;
    uVar5 = param_3[3];
    param_1[2] = param_3[2];
    param_1[3] = uVar5;
    param_3[2] = 0;
    param_3[3] = 7;
    *(undefined2 *)param_3 = 0;
    puVar8 = param_1;
    if (7 < (ulonglong)param_1[3]) {
      puVar8 = (undefined8 *)*param_1;
    }
    param_3 = param_4;
    if (7 < (ulonglong)param_4[3]) {
      param_3 = (undefined8 *)*param_4;
    }
    _Size = uVar3 * 2 + 2;
    pvVar9 = (void *)((longlong)puVar8 + uVar2 * 2);
  }
  memcpy(pvVar9,param_3,_Size);
  param_1[2] = uVar1;
  return param_1;
}


/* Function 180008bf4 FUN_180008bf4 */

undefined8 * FUN_180008bf4(undefined8 *param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  ulonglong uVar3;
  void *pvVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong in_stack_00000028;
  void *in_stack_00000030;
  longlong in_stack_00000038;
  
  puVar7 = (undefined8 *)0x0;
  *param_1 = 0;
  uVar6 = 7;
  param_1[2] = 0;
  uVar1 = in_stack_00000028 + in_stack_00000038;
  param_1[3] = 0;
  puVar5 = param_1;
  if (7 < uVar1) {
    uVar3 = uVar1 | 7;
    uVar6 = 0x7ffffffffffffffe;
    if ((uVar3 < 0x7fffffffffffffff) && (uVar6 = uVar3, uVar3 < 10)) {
      uVar6 = 10;
    }
    uVar3 = uVar6 + 1;
    if (uVar6 == 0xffffffffffffffff) {
      uVar3 = 0xffffffffffffffff;
    }
    if (0x7fffffffffffffff < uVar3) {
LAB_180008d32:
      FUN_180001488();
      pcVar2 = (code *)swi(3);
      puVar5 = (undefined8 *)(*pcVar2)();
      return puVar5;
    }
    uVar3 = uVar3 * 2;
    if (uVar3 < 0x1000) {
      if (uVar3 != 0) {
        puVar7 = (undefined8 *)operator_new(uVar3);
      }
    }
    else {
      if (uVar3 + 0x27 <= uVar3) goto LAB_180008d32;
      pvVar4 = operator_new(uVar3 + 0x27);
      if (pvVar4 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      puVar7 = (undefined8 *)((longlong)pvVar4 + 0x27U & 0xffffffffffffffe0);
      puVar7[-1] = pvVar4;
    }
    *param_1 = puVar7;
    puVar5 = puVar7;
  }
  param_1[3] = uVar6;
  param_1[2] = uVar1;
  memcpy(puVar5,L"<toast launch=\"",in_stack_00000028 * 2);
  memcpy((void *)(in_stack_00000028 * 2 + (longlong)puVar5),in_stack_00000030,in_stack_00000038 * 2)
  ;
  *(undefined2 *)((longlong)puVar5 + uVar1 * 2) = 0;
  return param_1;
}


/* Function 180008d40 FUN_180008d40 */

undefined8 * FUN_180008d40(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &PTR_FUN_18001e520;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 180008d6c FUN_180008d6c */

void FUN_180008d6c(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180008df4 FUN_180008df4 */

void FUN_180008df4(longlong *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = 0;
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,param_2,&local_18);
  if (-1 < iVar2) {
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    if (local_18 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18);
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180008e80 FUN_180008e80 */

void FUN_180008e80(void *param_1,char param_2)

{
  if (*(longlong *)((longlong)param_1 + 8) != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  if (param_2 != '\0') {
    free(param_1);
  }
  return;
}


/* Function 180008ed0 FUN_180008ed0 */

longlong FUN_180008ed0(longlong param_1)

{
  return param_1 + 8;
}


/* Function 180008ee0 FUN_180008ee0 */

TypeDescriptor * FUN_180008ee0(void)

{
  return &<lambda_68ff4cb3f062ab1b6453d1627779ef6e>::RTTI_Type_Descriptor;
}


/* Function 180008ef0 FUN_180008ef0 */

void FUN_180008ef0(longlong param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  if (-1 < iVar2) {
    return;
  }
  FUN_180001ad4(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 180008f20 FUN_180008f20 */

undefined8 * FUN_180008f20(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  
  *param_2 = &PTR_FUN_18001e1c0;
  lVar1 = *(longlong *)(param_1 + 8);
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
  }
  param_2[1] = lVar1;
  return param_2;
}


/* Function 180008f70 FUN_180008f70 */

undefined8 * FUN_180008f70(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  
  *param_2 = &PTR_FUN_18001e1c0;
  lVar1 = *(longlong *)(param_1 + 8);
  if (lVar1 != 0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1);
  }
  param_2[1] = lVar1;
  return param_2;
}


/* Function 180008fc0 FUN_180008fc0 */

void FUN_180008fc0(longlong param_1)

{
  FUN_1800071f0(param_1 + -0x10);
  return;
}


/* Function 180008fd0 FUN_180008fd0 */

void FUN_180008fd0(longlong param_1)

{
  abi_AddRef(param_1 + -8);
  return;
}


/* Function 180008fe0 FUN_180008fe0 */

void FUN_180008fe0(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_180007c70(param_1 + -8,param_2,param_3);
  return;
}


/* Function 180008ff0 FUN_180008ff0 */

void FUN_180008ff0(longlong param_1)

{
  FUN_180006cc0(param_1 + -0x10);
  return;
}


/* Function 180009000 FUN_180009000 */

void FUN_180009000(longlong param_1,undefined4 *param_2)

{
  FUN_180006950(param_1 + -8,param_2);
  return;
}


/* Function 180009010 FUN_180009010 */

void FUN_180009010(longlong param_1)

{
  FUN_180006880(param_1 + -8);
  return;
}


/* Function 180009020 FUN_180009020 */

void FUN_180009020(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_180006710(param_1 + -8,param_2,param_3);
  return;
}


/* Function 180009030 FUN_180009030 */

void FUN_180009030(longlong param_1,int *param_2,ulonglong *param_3)

{
  FUN_180006ad0(param_1 - 8,param_2,param_3);
  return;
}


/* Function 180009040 FUN_180009040 */

void FUN_180009040(longlong param_1,ulong *param_2,Guid **param_3)

{
  FUN_1800074cc(param_1 + -0x10,param_2,param_3);
  return;
}


/* Function 180009050 FUN_180009050 */

void FUN_180009050(longlong param_1,undefined8 param_2)

{
  FUN_180007524(param_1 + -8,param_2);
  return;
}


/* Function 180009060 FUN_180009060 */

void FUN_180009060(longlong param_1)

{
  FUN_1800071f0(param_1 + -8);
  return;
}


/* Function 180009070 FUN_180009070 */

void FUN_180009070(longlong param_1,undefined8 param_2)

{
  FUN_180006930(param_1 + -8,param_2);
  return;
}


/* Function 180009080 FUN_180009080 */

void FUN_180009080(longlong param_1,undefined8 param_2)

{
  FUN_180006df0(param_1 + -8,param_2);
  return;
}


/* Function 180009090 FUN_180009090 */

void FUN_180009090(longlong param_1,ulong *param_2,Guid **param_3)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_GetIids
            ((_Platform__Object_ *)(param_1 + -0x20),param_2,param_3);
  return;
}


/* Function 1800090a0 FUN_1800090a0 */

void FUN_1800090a0(longlong param_1)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_AddRef
            ((_Platform__Object_ *)(param_1 + -0x20));
  return;
}


/* Function 1800090b0 FUN_1800090b0 */

void FUN_1800090b0(longlong param_1)

{
  abi_AddRef(param_1 + -0x10);
  return;
}


/* Function 1800090c0 FUN_1800090c0 */

void FUN_1800090c0(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_180007c70(param_1 + -0x10,param_2,param_3);
  return;
}


/* Function 1800090d0 FUN_1800090d0 */

void FUN_1800090d0(longlong param_1)

{
  FUN_180006cc0(param_1 + -0x18);
  return;
}


/* Function 1800090e0 FUN_1800090e0 */

void FUN_1800090e0(longlong param_1,longlong *param_2,size_t param_3)

{
  FUN_1800062a0(param_1 + -8,param_2,param_3);
  return;
}


/* Function 1800090f0 FUN_1800090f0 */

void FUN_1800090f0(longlong param_1,undefined4 *param_2)

{
  FUN_180006950(param_1 + -0x10,param_2);
  return;
}


/* Function 180009100 FUN_180009100 */

void FUN_180009100(longlong param_1,longlong *param_2,size_t param_3)

{
  FUN_180006aa0(param_1 + -8,param_2,param_3);
  return;
}


/* Function 180009110 FUN_180009110 */

void FUN_180009110(longlong param_1,ulong *param_2,Guid **param_3)

{
  FUN_180007290(param_1 + -8,param_2,param_3);
  return;
}


/* Function 180009120 FUN_180009120 */

void FUN_180009120(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_1800073b0(param_1 + -8,param_2,param_3);
  return;
}


/* Function 180009130 FUN_180009130 */

void FUN_180009130(longlong param_1,int *param_2,ulonglong *param_3)

{
  FUN_180006ad0(param_1 - 0x10,param_2,param_3);
  return;
}


/* Function 180009140 FUN_180009140 */

void FUN_180009140(longlong param_1,undefined8 param_2)

{
  FUN_1800072e8(param_1 + -8,param_2);
  return;
}


/* Function 180009150 FUN_180009150 */

void FUN_180009150(longlong param_1,undefined8 param_2)

{
  FUN_180007524(param_1 + -0x10,param_2);
  return;
}


/* Function 180009160 FUN_180009160 */

void FUN_180009160(longlong param_1,ulong *param_2,Guid **param_3)

{
  FUN_1800068e0(param_1 + -8,param_2,param_3);
  return;
}


/* Function 180009170 FUN_180009170 */

void FUN_180009170(longlong param_1,undefined8 param_2)

{
  FUN_180006df0(param_1 + -0x10,param_2);
  return;
}


/* Function 180009180 FUN_180009180 */

void FUN_180009180(longlong param_1,ulong *param_2,Guid **param_3)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_GetIids
            ((_Platform__Object_ *)(param_1 + -8),param_2,param_3);
  return;
}


/* Function 180009190 FUN_180009190 */

void FUN_180009190(longlong param_1)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_AddRef
            ((_Platform__Object_ *)(param_1 + -8));
  return;
}


/* Function 1800091a0 FUN_1800091a0 */

void FUN_1800091a0(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_1800070a0(param_1 + -8,param_2,param_3);
  return;
}


/* Function 1800091b0 FUN_1800091b0 */

void FUN_1800091b0(longlong param_1,ulong *param_2,Guid **param_3)

{
  FUN_180007d8c(param_1 + -8,param_2,param_3);
  return;
}


/* Function 1800091c0 FUN_1800091c0 */

void FUN_1800091c0(longlong param_1,undefined8 param_2)

{
  FUN_180007de4(param_1 + -8,param_2);
  return;
}


/* Function 1800091d0 FUN_1800091d0 */

void FUN_1800091d0(longlong param_1,longlong *param_2)

{
  FUN_180006a18(param_1 + -0x18,param_2);
  return;
}


/* Function 1800091e0 FUN_1800091e0 */

void FUN_1800091e0(longlong param_1)

{
  FUN_180006cc0(param_1 + -0x20);
  return;
}


/* Function 1800091f0 FUN_1800091f0 */

void FUN_1800091f0(longlong param_1)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::
  [Platform::Details::IWeakReferenceSource]::GetWeakReference
            ((_Platform__Details__IWeakReferenceSource_ *)(param_1 + -0x18));
  return;
}


/* Function 180009200 FUN_180009200 */

void FUN_180009200(longlong param_1,ulong *param_2,Guid **param_3)

{
  FUN_180007290(param_1 + -0x10,param_2,param_3);
  return;
}


/* Function 180009210 FUN_180009210 */

void FUN_180009210(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_1800073b0(param_1 + -0x10,param_2,param_3);
  return;
}


/* Function 180009220 FUN_180009220 */

void FUN_180009220(longlong param_1)

{
  abi_AddRef(param_1 + -8);
  return;
}


/* Function 180009230 FUN_180009230 */

void FUN_180009230(longlong param_1,int *param_2,ulonglong *param_3)

{
  FUN_180006ad0(param_1 - 0x18,param_2,param_3);
  return;
}


/* Function 180009240 FUN_180009240 */

void FUN_180009240(longlong param_1,undefined8 param_2)

{
  FUN_1800072e8(param_1 + -0x10,param_2);
  return;
}


/* Function 180009250 FUN_180009250 */

void FUN_180009250(longlong param_1,ulong *param_2,Guid **param_3)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_GetIids
            ((_Platform__Object_ *)(param_1 + -0x10),param_2,param_3);
  return;
}


/* Function 180009260 FUN_180009260 */

void FUN_180009260(longlong param_1)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_AddRef
            ((_Platform__Object_ *)(param_1 + -0x10));
  return;
}


/* Function 180009270 FUN_180009270 */

void FUN_180009270(longlong param_1,int *param_2,longlong *param_3)

{
  FUN_1800070a0(param_1 + -0x10,param_2,param_3);
  return;
}


/* Function 180009280 FUN_180009280 */

void FUN_180009280(longlong param_1,ulong *param_2,Guid **param_3)

{
  FUN_180007d8c(param_1 + -0x10,param_2,param_3);
  return;
}


/* Function 180009290 FUN_180009290 */

void FUN_180009290(longlong param_1,undefined8 param_2)

{
  FUN_180007de4(param_1 + -0x10,param_2);
  return;
}


/* Function 1800092a0 FUN_1800092a0 */

void FUN_1800092a0(longlong param_1)

{
  FUN_180006cc0(param_1 + -8);
  return;
}


/* Function 1800092b0 FUN_1800092b0 */

void FUN_1800092b0(longlong param_1,undefined4 *param_2)

{
  FUN_180006950(param_1 + -0x20,param_2);
  return;
}


/* Function 1800092c0 FUN_1800092c0 */

void FUN_1800092c0(longlong param_1,ulong *param_2,Guid **param_3)

{
  FUN_1800074cc(param_1 + -8,param_2,param_3);
  return;
}


/* Function 1800092d0 FUN_1800092d0 */

void FUN_1800092d0(longlong param_1,int *param_2,ulonglong *param_3)

{
  FUN_180006ad0(param_1 - 0x20,param_2,param_3);
  return;
}


/* Function 1800092e0 FUN_1800092e0 */

void FUN_1800092e0(longlong param_1,undefined8 param_2)

{
  FUN_180006df0(param_1 + -0x20,param_2);
  return;
}


/* Function 1800092f0 FUN_1800092f0 */

void FUN_1800092f0(longlong param_1)

{
  Platform::WriteOnlyArray<class_Platform::String_^___ptr64,1>::[Platform::Object]::__abi_AddRef
            ((_Platform__Object_ *)(param_1 + -0x18));
  return;
}


/* Function 1800092fc FUN_1800092fc */

void FUN_1800092fc(undefined8 *param_1,undefined8 *param_2)

{
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,0);
  if (param_1 != param_2) {
    Platform::Details::Heap::Free(param_1);
  }
  return;
}


/* Function 180009334 FUN_180009334 */

void FUN_180009334(longlong *param_1)

{
  longlong lVar1;
  longlong **pplVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  bool bVar7;
  undefined1 auStack_68 [32];
  longlong local_48;
  longlong *local_38;
  longlong *plStack_30;
  longlong *local_28;
  ulonglong local_20;
  
  local_20 = DAT_18001e100 ^ (ulonglong)auStack_68;
  lVar1 = *param_1;
  if (*(char *)(lVar1 + 0x81) == '\0') {
    local_38 = (longlong *)0x0;
    plStack_30 = (longlong *)0x0;
    local_28 = (longlong *)0x0;
    bVar7 = false;
    iVar4 = _Mtx_lock(lVar1 + 0x18);
    if (iVar4 != 0) {
      std::_Throw_C_error(iVar4);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    plVar5 = (longlong *)0x0;
    plVar6 = (longlong *)0x0;
    if (*(char *)(*param_1 + 0x81) == '\0') {
      *(undefined1 *)(*param_1 + 0x81) = 1;
      pplVar2 = (longlong **)*param_1;
      if (&local_38 != pplVar2) {
        plVar5 = *pplVar2;
        *pplVar2 = (longlong *)0x0;
        plVar6 = pplVar2[1];
        pplVar2[1] = (longlong *)0x0;
        local_28 = pplVar2[2];
        pplVar2[2] = (longlong *)0x0;
        local_38 = plVar5;
        plStack_30 = plVar6;
      }
      bVar7 = true;
    }
    _Mtx_unlock(lVar1 + 0x18);
    lVar1 = *(longlong *)(*param_1 + 0x70);
    if ((bVar7) && (plVar5 != plStack_30)) {
      do {
        bVar7 = lVar1 == 0;
        if (bVar7) {
          local_48 = *plVar5 + 0x10;
        }
        else {
          local_48 = *param_1 + 0x70;
        }
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(*plVar5,1,!bVar7,!bVar7);
        plVar5 = plVar5 + 2;
      } while (plVar5 != plVar6);
    }
    FUN_1800097d0((longlong *)&local_38);
  }
  FUN_18000c7f0(local_20 ^ (ulonglong)auStack_68);
  return;
}


/* Function 180009484 FUN_180009484 */

void FUN_180009484(longlong *param_1,void *param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  undefined8 *puVar5;
  void *_Memory;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStack_d8 [32];
  longlong local_b8;
  undefined1 local_b0 [16];
  undefined1 local_a0 [16];
  undefined1 local_90 [16];
  undefined1 *local_80;
  undefined8 local_78;
  void *pvStack_70;
  undefined8 local_68;
  longlong lStack_60;
  undefined1 *local_58;
  undefined1 *local_50;
  undefined8 *local_48;
  undefined8 *local_40;
  void *local_38;
  ulonglong local_30;
  
  local_30 = DAT_18001e100 ^ (ulonglong)auStack_d8;
  pvStack_70 = (void *)0x0;
  local_68 = 0;
  lVar7 = 0;
  lStack_60 = 0;
  local_38 = param_2;
  __ExceptionPtrCopy(local_90,param_2);
  local_58 = local_90;
  __ExceptionPtrCopy(local_b0,local_90);
  local_50 = local_b0;
  lVar6 = *param_1 + 0x18;
  local_b8 = lVar6;
  iVar4 = _Mtx_lock(lVar6);
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  lVar3 = *param_1;
  if (((*(char *)(lVar3 + 0x80) == '\0') && (*(char *)(lVar3 + 0x81) == '\0')) &&
     (*(longlong *)(lVar3 + 0x70) == 0)) {
    __ExceptionPtrCopy(local_a0,local_b0);
    local_80 = local_a0;
    puVar5 = (undefined8 *)operator_new(0x48);
    *puVar5 = 0;
    puVar5[1] = 0;
    *(undefined4 *)(puVar5 + 1) = 1;
    *(undefined4 *)((longlong)puVar5 + 0xc) = 1;
    *puVar5 = &PTR_FUN_18001e4b0;
    puVar1 = puVar5 + 2;
    *(undefined4 *)puVar1 = 0;
    local_48 = puVar5;
    local_40 = puVar1;
    __ExceptionPtrCopy(puVar5 + 3,local_a0);
    FUN_18000b650(puVar5 + 5,&local_78);
    __ExceptionPtrDestroy(local_a0);
    lVar7 = *param_1;
    *(undefined8 **)(lVar7 + 0x70) = puVar1;
    lVar3 = *(longlong *)(lVar7 + 0x78);
    *(undefined8 **)(lVar7 + 0x78) = puVar5;
    if (lVar3 != 0) {
      LOCK();
      piVar2 = (int *)(lVar3 + 8);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      lVar6 = local_b8;
      if (iVar4 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
        LOCK();
        piVar2 = (int *)(lVar3 + 0xc);
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        lVar6 = local_b8;
        if (iVar4 == 1) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
          lVar6 = local_b8;
        }
      }
    }
    _Mtx_unlock(lVar6);
    __ExceptionPtrDestroy(local_b0);
    FUN_180009334(param_1);
    lVar7 = lStack_60;
  }
  else {
    _Mtx_unlock(lVar6);
    __ExceptionPtrDestroy(local_b0);
  }
  __ExceptionPtrDestroy(local_90);
  if (pvStack_70 != (void *)0x0) {
    _Memory = pvStack_70;
    if ((0xfff < (ulonglong)((lVar7 - (longlong)pvStack_70 >> 3) * 8)) &&
       (_Memory = *(void **)((longlong)pvStack_70 + -8),
       0x1f < (ulonglong)((longlong)pvStack_70 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  __ExceptionPtrDestroy(param_2);
  FUN_18000c7f0(local_30 ^ (ulonglong)auStack_d8);
  return;
}


/* Function 1800096c4 FUN_1800096c4 */

void FUN_1800096c4(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)*param_1;
  if (plVar4 != (longlong *)param_1[1]) {
    do {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(*plVar4,1,0,0,*plVar4 + 0x10);
      plVar4 = plVar4 + 2;
    } while (plVar4 != (longlong *)param_1[1]);
  }
  lVar3 = param_1[0xf];
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      LOCK();
      piVar1 = (int *)(lVar3 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      }
    }
  }
  _Mtx_destroy_in_situ(param_1 + 3);
  FUN_1800097d0(param_1);
  return;
}


/* Function 180009770 FUN_180009770 */

void FUN_180009770(longlong param_1)

{
  FUN_1800096c4((longlong *)(param_1 + 0x10));
  return;
}


/* Function 180009780 FUN_180009780 */

undefined8 * FUN_180009780(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &PTR_FUN_18001e368;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 1800097b0 FUN_1800097b0 */

void FUN_1800097b0(longlong *param_1)

{
  if (param_1 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,1);
  }
  return;
}


/* Function 1800097d0 FUN_1800097d0 */

void FUN_1800097d0(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  void *pvVar4;
  void *pvVar5;
  
  pvVar4 = (void *)*param_1;
  if (pvVar4 != (void *)0x0) {
    pvVar5 = (void *)param_1[1];
    if (pvVar4 != pvVar5) {
      do {
        lVar3 = *(longlong *)((longlong)pvVar4 + 8);
        if (lVar3 != 0) {
          LOCK();
          piVar1 = (int *)(lVar3 + 8);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
            LOCK();
            piVar1 = (int *)(lVar3 + 0xc);
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
            }
          }
        }
        pvVar4 = (void *)((longlong)pvVar4 + 0x10);
      } while (pvVar4 != pvVar5);
      pvVar4 = (void *)*param_1;
    }
    pvVar5 = pvVar4;
    if ((0xfff < (param_1[2] - (longlong)pvVar4 & 0xfffffffffffffff0U)) &&
       (pvVar5 = *(void **)((longlong)pvVar4 + -8),
       0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar5);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* Function 1800098a8 FUN_1800098a8 */

void FUN_1800098a8(undefined8 param_1,String *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800098ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __abi_details::__abi_cast_String_to_Object(param_2);
  return;
}


/* Function 1800098b4 FUN_1800098b4 */

void FUN_1800098b4(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  undefined1 auStack_38 [32];
  longlong local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  lVar1 = *param_1;
  if (lVar1 != param_2) {
    if (lVar1 != 0) {
      WindowsDeleteString(lVar1);
    }
    *param_1 = 0;
    if (param_2 != 0) {
      iVar3 = WindowsDuplicateString(param_2,&local_18);
      if (iVar3 < 0) {
        FUN_180001ad4(iVar3);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      *param_1 = local_18;
    }
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
  return;
}


/* Function 180009934 FUN_180009934 */

void FUN_180009934(longlong param_1)

{
  undefined1 auStack_78 [104];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_78;
  if (*(longlong *)(param_1 + 0x38) != 0) {
    if (*(longlong *)(param_1 + 0x38) == 0) {
      std::_Xbad_function_call();
    }
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* Function 180009984 FUN_180009984 */

void FUN_180009984(longlong *param_1)

{
  longlong *plVar1;
  
  FUN_180009934((longlong)param_1);
  plVar1 = (longlong *)param_1[7];
  if (plVar1 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar1,plVar1 != param_1);
    param_1[7] = 0;
  }
  return;
}


/* Function 1800099bc FUN_1800099bc */

undefined1 FUN_1800099bc(void)

{
  return 1;
}


/* Function 1800099c0 FUN_1800099c0 */

void FUN_1800099c0(longlong param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  longlong lVar4;
  void *_Memory;
  
  pvVar3 = *(void **)(param_1 + 0x40);
  if (pvVar3 != (void *)0x0) {
    _Memory = pvVar3;
    if ((0xfff < (ulonglong)((*(longlong *)(param_1 + 0x50) - (longlong)pvVar3 >> 3) * 8)) &&
       (_Memory = *(void **)((longlong)pvVar3 + -8),
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 0x20));
  if (*(longlong *)(param_1 + 0x18) != 0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  lVar4 = *(longlong *)(param_1 + 8);
  if (lVar4 != 0) {
    LOCK();
    piVar1 = (int *)(lVar4 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
      LOCK();
      piVar1 = (int *)(lVar4 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
      }
    }
  }
  return;
}


/* Function 180009aa4 FUN_180009aa4 */

void FUN_180009aa4(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


/* Function 180009aac FUN_180009aac */

void FUN_180009aac(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  int iVar4;
  long lVar5;
  longlong *plVar6;
  longlong *_Memory;
  bool bVar7;
  
  bVar7 = false;
  iVar4 = _Mtx_lock(param_1 + 0x18);
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  if (*(longlong **)(param_1 + 0x68) == (longlong *)0x0) {
    bVar7 = true;
  }
  else {
    plVar6 = (longlong *)0x0;
    _Memory = *(longlong **)(param_1 + 0x68);
    do {
      plVar1 = (longlong *)_Memory[1];
      if ((longlong *)*_Memory == param_2) {
        if (plVar6 == (longlong *)0x0) {
          *(longlong **)(param_1 + 0x68) = plVar1;
        }
        else {
          plVar6[1] = (longlong)plVar1;
        }
        if (_Memory[1] == 0) {
          *(longlong **)(param_1 + 0x70) = plVar6;
        }
        free(_Memory);
        break;
      }
      plVar6 = _Memory;
      _Memory = plVar1;
    } while (plVar1 != (longlong *)0x0);
    LOCK();
    *(undefined4 *)(param_2 + 2) = 2;
    UNLOCK();
    LOCK();
    plVar6 = param_2 + 1;
    lVar3 = *plVar6;
    *(int *)plVar6 = (int)*plVar6 + -1;
    UNLOCK();
    if ((int)lVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_2);
    }
  }
  _Mtx_unlock(param_1 + 0x18);
  if (bVar7) {
    LOCK();
    iVar4 = (int)param_2[2];
    bVar7 = iVar4 == 0;
    if (bVar7) {
      *(int *)(param_2 + 2) = 1;
      iVar4 = 0;
    }
    UNLOCK();
    if ((((!bVar7) && (iVar4 != 0)) && (iVar4 != 1)) &&
       (((iVar4 != 2 && (iVar4 != 3)) &&
        (lVar5 = Concurrency::details::platform::GetCurrentThreadId(), iVar4 != lVar5)))) {
      LOCK();
      lVar3 = param_2[2];
      *(int *)(param_2 + 2) = 2;
      UNLOCK();
      if ((int)lVar3 != 3) {
        plVar6 = param_2 + 0xc;
        iVar4 = _Mtx_lock(plVar6);
        if (iVar4 != 0) {
          std::_Throw_C_error(iVar4);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        while ((char)param_2[0x16] == '\0') {
          _Cnd_wait(param_2 + 3,plVar6);
        }
        _Mtx_unlock(plVar6);
      }
    }
  }
  return;
}


/* Function 180009bec FUN_180009bec */

void FUN_180009bec(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  
  *param_1 = &PTR_FUN_18001e3e8;
  if ((longlong *)param_1[0x10] != (longlong *)0x0) {
    FUN_180009aac(param_1[0xf],(longlong *)param_1[0x10]);
    LOCK();
    piVar1 = (int *)(param_1[0x10] + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
    param_1[0x10] = 0;
  }
  puVar3 = (undefined8 *)param_1[0x36];
  if (puVar3 != (undefined8 *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar3,puVar3 != param_1 + 0x2f);
    param_1[0x36] = 0;
  }
  FUN_180009db4(param_1);
  return;
}


/* Function 180009c80 FUN_180009c80 */

undefined8 * FUN_180009c80(undefined8 *param_1,uint param_2)

{
  FUN_180009bec(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 180009cc0 FUN_180009cc0 */

/* WARNING: Switch with 1 destination removed at 0x000180009ccc */

void FUN_180009cc0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180012b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)**(undefined8 **)(param_1 + 0x10))((undefined8 *)(param_1 + 0x10),0);
  return;
}


/* Function 180009ce0 FUN_180009ce0 */

undefined8 * FUN_180009ce0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &PTR_FUN_18001e388;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 180009d10 FUN_180009d10 */

undefined8 * FUN_180009d10(undefined8 *param_1,uint param_2)

{
  FUN_180009db4(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 180009d44 FUN_180009d44 */

void FUN_180009d44(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0xa0);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      LOCK();
      piVar1 = (int *)(lVar3 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      }
    }
  }
  _Mtx_destroy_in_situ(param_1 + 0x48);
                    /* WARNING: Could not recover jumptable at 0x000180009dad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Cnd_destroy_in_situ(param_1);
  return;
}


/* Function 180009db4 FUN_180009db4 */

void FUN_180009db4(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  longlong lVar4;
  void *_Memory;
  
  *param_1 = &PTR_FUN_18001e3a8;
  if (param_1[0xf] != 2) {
    LOCK();
    piVar1 = (int *)(param_1[0xf] + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
  }
  pvVar3 = (void *)param_1[0x29];
  if (pvVar3 != (void *)0x0) {
    _Memory = pvVar3;
    if ((0xfff < (param_1[0x2b] - (longlong)pvVar3 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar3 + -8),
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2b] = 0;
  }
  FUN_180009d44((longlong)(param_1 + 0x11));
  _Mtx_destroy_in_situ(param_1 + 4);
  lVar4 = param_1[3];
  if (lVar4 != 0) {
    LOCK();
    piVar1 = (int *)(lVar4 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
      LOCK();
      piVar1 = (int *)(lVar4 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
      }
    }
  }
  return;
}


/* Function 180009eb0 FUN_180009eb0 */

undefined8 * FUN_180009eb0(longlong param_1,undefined8 *param_2)

{
  *param_2 = &PTR_FUN_18001e3b8;
  param_2[1] = *(undefined8 *)(param_1 + 8);
  return param_2;
}


/* Function 180009ed0 FUN_180009ed0 */

void FUN_180009ed0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_18000b9b4(*(longlong *)(param_1 + 8),param_2,param_3,param_4);
  return;
}


/* Function 180009ee0 FUN_180009ee0 */

TypeDescriptor * FUN_180009ee0(void)

{
  return &<lambda_763529b0c7473cbc215a52d189ac9b18>::RTTI_Type_Descriptor;
}


/* Function 180009ef0 FUN_180009ef0 */

void FUN_180009ef0(void *param_1,char param_2)

{
  if (param_2 != '\0') {
    free(param_1);
  }
  return;
}


/* Function 180009f10 FUN_180009f10 */

void FUN_180009f10(longlong param_1,char param_2,char param_3,undefined8 param_4,undefined8 *param_5
                  )

{
  int *piVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_98 [32];
  longlong local_78;
  undefined **local_68;
  longlong local_60;
  undefined ***local_30;
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStack_98;
  local_78 = param_1 + 0x20;
  iVar4 = _Mtx_lock();
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  if (param_3 == '\0') {
    if (((*(int *)(param_1 + 8) == 3) || (*(int *)(param_1 + 8) == 4)) ||
       ((*(int *)(param_1 + 8) == 2 && (param_2 == '\0')))) goto LAB_18000a102;
  }
  else {
    if (*(int *)(param_1 + 8) == 4) {
LAB_18000a102:
      _Mtx_unlock(local_78);
      goto LAB_18000a10f;
    }
    lVar5 = param_5[1];
    if (lVar5 != 0) {
      LOCK();
      *(int *)(lVar5 + 8) = *(int *)(lVar5 + 8) + 1;
      UNLOCK();
      lVar5 = param_5[1];
    }
    *(undefined8 *)(param_1 + 0x10) = *param_5;
    lVar2 = *(longlong *)(param_1 + 0x18);
    *(longlong *)(param_1 + 0x18) = lVar5;
    if (lVar2 != 0) {
      LOCK();
      piVar1 = (int *)(lVar2 + 8);
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar2);
        LOCK();
        piVar1 = (int *)(lVar2 + 0xc);
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar4 == 1) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar2);
        }
      }
    }
  }
  if (param_2 == '\0') {
    iVar4 = 0;
    if (*(int *)(param_1 + 8) == 1) {
      iVar4 = 2;
    }
    *(undefined4 *)(param_1 + 8) = 2;
    Concurrency::details::_TaskEventLogger::_LogCancelTask((_TaskEventLogger *)(param_1 + 0x160));
  }
  else {
    *(undefined4 *)(param_1 + 8) = 4;
    iVar4 = 1;
  }
  _Mtx_unlock(local_78);
  if (iVar4 == 1) {
    iVar4 = _Mtx_lock(param_1 + 0xd0);
    if (iVar4 != 0) {
      std::_Throw_C_error(iVar4);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if (*(int *)(param_1 + 0x138) < 2) {
      *(undefined4 *)(param_1 + 0x138) = 2;
    }
    _Cnd_broadcast(param_1 + 0x88);
    _Mtx_unlock(param_1 + 0xd0);
    if (*(longlong *)(param_1 + 0x70) != 0) {
      local_68 = &PTR_FUN_18001e3b8;
      local_30 = &local_68;
      local_60 = param_1;
      FUN_18000ae40((longlong)&local_68,0x10);
      if (local_30 != (undefined ***)0x0) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)
                  (local_30,CONCAT71((int7)((ulonglong)&local_68 >> 8),local_30 != &local_68));
      }
    }
  }
  else if ((iVar4 == 2) && (*(longlong *)(param_1 + 0x1b0) != 0)) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
LAB_18000a10f:
  FUN_18000c7f0(local_28 ^ (ulonglong)auStack_98);
  return;
}


/* Function 18000a134 FUN_18000a134 */

undefined8 * FUN_18000a134(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  lVar5 = param_3[1];
  if (lVar5 != 0) {
    LOCK();
    *(int *)(lVar5 + 8) = *(int *)(lVar5 + 8) + 1;
    UNLOCK();
    lVar5 = param_3[1];
  }
  uVar3 = *param_3;
  uVar4 = param_3[2];
  *param_1 = &PTR_FUN_18001e3a8;
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined2 *)((longlong)param_1 + 0xc) = 0;
  _Mtx_init_in_situ(param_1 + 4,2);
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  if (lVar5 != 0) {
    LOCK();
    *(int *)(lVar5 + 8) = *(int *)(lVar5 + 8) + 1;
    UNLOCK();
  }
  _Cnd_init_in_situ(param_1 + 0x11);
  _Mtx_init_in_situ(param_1 + 0x1a,2);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  if (lVar5 != 0) {
    LOCK();
    *(int *)(lVar5 + 8) = *(int *)(lVar5 + 8) + 1;
    UNLOCK();
  }
  param_1[0x24] = uVar3;
  param_1[0x25] = lVar5;
  param_1[0x26] = uVar4;
  *(undefined4 *)(param_1 + 0x27) = 0;
  if (lVar5 != 0) {
    LOCK();
    piVar1 = (int *)(lVar5 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      LOCK();
      piVar1 = (int *)(lVar5 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      }
    }
  }
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x28] = 0;
  param_1[0x2c] = param_1;
  *(undefined2 *)(param_1 + 0x2d) = 0;
  param_1[0xf] = param_2;
  if (param_2 != 2) {
    LOCK();
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
    UNLOCK();
  }
  if (lVar5 != 0) {
    LOCK();
    piVar1 = (int *)(lVar5 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      LOCK();
      piVar1 = (int *)(lVar5 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      }
    }
  }
  *param_1 = &PTR_FUN_18001e3e8;
  param_1[0x36] = 0;
  lVar5 = param_3[1];
  if (lVar5 != 0) {
    LOCK();
    piVar1 = (int *)(lVar5 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      LOCK();
      piVar1 = (int *)(lVar5 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      }
    }
  }
  return param_1;
}


/* Function 18000a330 FUN_18000a330 */

undefined8 * FUN_18000a330(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &PTR_FUN_18001e3f8;
  _Mtx_destroy_in_situ(param_1 + 0xc);
  _Cnd_destroy_in_situ(param_1 + 3);
  *param_1 = &PTR_FUN_18001e428;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 18000a390 FUN_18000a390 */

undefined8 * FUN_18000a390(undefined8 *param_1,ulonglong param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1[0x19] != 0) {
    LOCK();
    piVar1 = (int *)(param_1[0x19] + 0xc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
  }
  *param_1 = &PTR_FUN_18001e3f8;
  _Mtx_destroy_in_situ(param_1 + 0xc);
  _Cnd_destroy_in_situ(param_1 + 3);
  *param_1 = &PTR_FUN_18001e428;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 18000a410 FUN_18000a410 */

void FUN_18000a410(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  bool bVar6;
  undefined1 auStack_58 [32];
  longlong local_38;
  longlong local_28;
  longlong lStack_20;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_58;
  local_28 = 0;
  lStack_20 = 0;
  lVar3 = *(longlong *)(param_1 + 200);
  if (lVar3 != 0) {
    iVar5 = *(int *)(lVar3 + 8);
    do {
      if (iVar5 == 0) goto LAB_18000a45e;
      LOCK();
      iVar2 = *(int *)(lVar3 + 8);
      bVar6 = iVar5 == iVar2;
      if (bVar6) {
        *(int *)(lVar3 + 8) = iVar5 + 1;
        iVar2 = iVar5;
      }
      iVar5 = iVar2;
      UNLOCK();
    } while (!bVar6);
    local_28 = *(longlong *)(param_1 + 0xc0);
    lStack_20 = *(longlong *)(param_1 + 200);
  }
LAB_18000a45e:
  lVar3 = lStack_20;
  if (local_28 != 0) {
    local_38 = local_28 + 0x10;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_28,0,0,0);
  }
  lVar4 = lStack_20;
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 8);
    iVar5 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lStack_20);
      LOCK();
      piVar1 = (int *)(lVar4 + 0xc);
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar5 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)();
      }
    }
  }
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_58);
  return;
}


/* Function 18000a4f8 FUN_18000a4f8 */

void FUN_18000a4f8(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(longlong *)(param_1 + 8) != 0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 8) + 0xc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
  }
  return;
}


/* Function 18000a524 FUN_18000a524 */

void FUN_18000a524(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 *_Dst;
  bool bVar7;
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  longlong local_50;
  longlong *local_48;
  longlong local_40;
  longlong lStack_38;
  ulonglong local_30;
  
  local_30 = DAT_18001e100 ^ (ulonglong)auStack_78;
  local_40 = 0;
  lStack_38 = 0;
  lVar3 = param_2[1];
  bVar7 = true;
  if (lVar3 != 0) {
    local_40 = *param_2;
    LOCK();
    *(int *)(lVar3 + 0xc) = *(int *)(lVar3 + 0xc) + 1;
    UNLOCK();
    lStack_38 = lVar3;
  }
  local_48 = param_2;
  _Dst = (undefined8 *)operator_new(0xd0);
  local_58 = _Dst;
  memset(_Dst,0,0xd0);
  *_Dst = &PTR_FUN_18001e428;
  *(undefined4 *)(_Dst + 1) = 1;
  *_Dst = &PTR_FUN_18001e3f8;
  *(undefined4 *)(_Dst + 2) = 3;
  _Cnd_init_in_situ(_Dst + 3);
  puVar1 = _Dst + 0xc;
  _Mtx_init_in_situ(puVar1,2);
  *(undefined1 *)(_Dst + 0x16) = 0;
  _Dst[0x17] = 0;
  *_Dst = &PTR_FUN_18001e410;
  _Dst[0x18] = 0;
  _Dst[0x19] = 0;
  if (lStack_38 != 0) {
    _Dst[0x18] = local_40;
    _Dst[0x19] = lStack_38;
    LOCK();
    *(int *)(lStack_38 + 0xc) = *(int *)(lStack_38 + 0xc) + 1;
    UNLOCK();
  }
  *(undefined8 **)(param_1 + 0x80) = _Dst;
  lVar3 = *(longlong *)(param_1 + 0x78);
  LOCK();
  *(undefined4 *)(_Dst + 2) = 0;
  UNLOCK();
  LOCK();
  *(int *)(_Dst + 1) = *(int *)(_Dst + 1) + 1;
  UNLOCK();
  _Dst[0x17] = lVar3;
  if (*(int *)(lVar3 + 0x10) == 0) {
    local_50 = lVar3 + 0x18;
    iVar5 = _Mtx_lock();
    if (iVar5 != 0) {
      std::_Throw_C_error(iVar5);
    }
    if (*(int *)(lVar3 + 0x10) == 0) {
      bVar7 = false;
      local_58 = (undefined8 *)operator_new(0x10);
      *local_58 = _Dst;
      local_58[1] = 0;
      if (*(longlong *)(lVar3 + 0x68) == 0) {
        *(undefined8 **)(lVar3 + 0x68) = local_58;
      }
      else {
        *(undefined8 **)(*(longlong *)(lVar3 + 0x70) + 8) = local_58;
      }
      *(undefined8 **)(lVar3 + 0x70) = local_58;
    }
    _Mtx_unlock(local_50);
    if (!bVar7) goto LAB_18000a734;
  }
  lVar6 = Concurrency::details::platform::GetCurrentThreadId();
  LOCK();
  bVar7 = *(int *)(_Dst + 2) == 0;
  if (bVar7) {
    *(long *)(_Dst + 2) = lVar6;
  }
  UNLOCK();
  if (bVar7) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(_Dst);
    LOCK();
    iVar5 = *(int *)(_Dst + 2);
    bVar7 = lVar6 == iVar5;
    if (bVar7) {
      *(int *)(_Dst + 2) = 3;
      iVar5 = lVar6;
    }
    UNLOCK();
    if (!bVar7) {
      lVar6 = iVar5;
    }
    if (lVar6 == 2) {
      iVar5 = _Mtx_lock(puVar1);
      if (iVar5 != 0) {
        std::_Throw_C_error(iVar5);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *(undefined1 *)(_Dst + 0x16) = 1;
      _Mtx_unlock(puVar1);
      _Cnd_broadcast(_Dst + 3);
    }
  }
  LOCK();
  piVar2 = (int *)(_Dst + 1);
  iVar5 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar5 == 1) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(_Dst);
  }
LAB_18000a734:
  if (lStack_38 != 0) {
    LOCK();
    piVar2 = (int *)(lStack_38 + 0xc);
    iVar5 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
  }
  if (param_2[1] != 0) {
    LOCK();
    piVar2 = (int *)(param_2[1] + 0xc);
    iVar5 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
  }
  FUN_18000c7f0(local_30 ^ (ulonglong)auStack_78);
  return;
}


/* Function 18000a7a0 FUN_18000a7a0 */

undefined8 * FUN_18000a7a0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &PTR_FUN_18001e428;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 18000a7d0 FUN_18000a7d0 */

void FUN_18000a7d0(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,1);
  }
  return;
}


/* Function 18000a7f0 FUN_18000a7f0 */

void FUN_18000a7f0(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    LOCK();
    piVar1 = (int *)(*param_1 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    }
  }
  *param_1 = 0;
  return;
}


/* Function 18000a828 FUN_18000a828 */

void FUN_18000a828(void)

{
  code *pcVar1;
  
  std::_Xlength_error("vector too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* Function 18000a83c FUN_18000a83c */

void FUN_18000a83c(longlong *param_1,ulonglong param_2)

{
  code *pcVar1;
  void *pvVar2;
  void *_Memory;
  ulonglong uVar3;
  void *pvVar4;
  ulonglong uVar5;
  
  if (0x1fffffffffffffff < param_2) {
    FUN_18000a828();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pvVar2 = (void *)*param_1;
  uVar3 = param_1[2] - (longlong)pvVar2 >> 3;
  if (0x1fffffffffffffff - (uVar3 >> 1) < uVar3) {
    uVar5 = 0x1fffffffffffffff;
  }
  else {
    uVar5 = (uVar3 >> 1) + uVar3;
    if (uVar5 < param_2) {
      uVar5 = param_2;
    }
  }
  pvVar4 = (void *)0x0;
  if (pvVar2 != (void *)0x0) {
    _Memory = pvVar2;
    if ((0xfff < uVar3 << 3) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) goto LAB_18000a8ff;
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  if (0x1fffffffffffffff < uVar5) {
LAB_18000a938:
    FUN_180001488();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  uVar5 = uVar5 * 8;
  if (uVar5 < 0x1000) {
    if (uVar5 != 0) {
      pvVar4 = operator_new(uVar5);
    }
  }
  else {
    if (uVar5 + 0x27 <= uVar5) goto LAB_18000a938;
    pvVar2 = operator_new(uVar5 + 0x27);
    if (pvVar2 == (void *)0x0) {
LAB_18000a8ff:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    pvVar4 = (void *)((longlong)pvVar2 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)pvVar4 + -8) = pvVar2;
  }
  *param_1 = (longlong)pvVar4;
  param_1[1] = (longlong)pvVar4;
  param_1[2] = (longlong)(uVar5 + (longlong)pvVar4);
  return;
}


/* Function 18000a940 FUN_18000a940 */

void FUN_18000a940(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar3 = param_1[1];
  for (lVar5 = *param_1; lVar5 != lVar3; lVar5 = lVar5 + 0x10) {
    lVar4 = *(longlong *)(lVar5 + 8);
    if (lVar4 != 0) {
      LOCK();
      piVar1 = (int *)(lVar4 + 8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
        LOCK();
        piVar1 = (int *)(lVar4 + 0xc);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
        }
      }
    }
  }
  return;
}


/* Function 18000a9b4 FUN_18000a9b4 */

void FUN_18000a9b4(longlong *param_1,undefined8 *param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined8 *puVar6;
  longlong lVar7;
  void *pvVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined8 **ppuVar11;
  undefined8 *puVar12;
  void *pvVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  ulonglong uVar16;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  ulonglong local_a0;
  undefined8 *local_98;
  undefined8 *local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  longlong *local_68;
  undefined8 *local_60;
  undefined8 *local_58;
  longlong *local_50;
  ulonglong local_48;
  
  local_48 = DAT_18001e100 ^ (ulonglong)auStack_c8;
  lVar3 = *param_1;
  lVar7 = param_1[1] - *param_1 >> 4;
  local_a8 = param_3;
  if (lVar7 == 0xfffffffffffffff) {
    FUN_18000a828();
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  uVar16 = lVar7 + 1;
  uVar9 = param_1[2] - *param_1 >> 4;
  local_a0 = uVar16;
  if (0xfffffffffffffff - (uVar9 >> 1) < uVar9) {
LAB_18000acb0:
    FUN_180001488();
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  uVar9 = (uVar9 >> 1) + uVar9;
  uVar14 = uVar16;
  if (uVar16 <= uVar9) {
    uVar14 = uVar9;
  }
  if (0xfffffffffffffff < uVar14) goto LAB_18000acb0;
  uVar9 = uVar14 * 0x10;
  if (uVar9 < 0x1000) {
    puVar15 = (undefined8 *)0x0;
    if (uVar9 != 0) {
      puVar15 = (undefined8 *)operator_new(uVar9);
    }
  }
  else {
    if (uVar9 + 0x27 <= uVar9) goto LAB_18000acb0;
    pvVar8 = operator_new(uVar9 + 0x27);
    if (pvVar8 == (void *)0x0) goto LAB_18000aca3;
    puVar15 = (undefined8 *)((longlong)pvVar8 + 0x27U & 0xffffffffffffffe0);
    puVar15[-1] = pvVar8;
  }
  puVar12 = (undefined8 *)(((longlong)param_2 - lVar3 & 0xfffffffffffffff0U) + (longlong)puVar15);
  *puVar12 = 0;
  puVar12[1] = 0;
  if (local_a8[1] != 0) {
    LOCK();
    piVar1 = (int *)(local_a8[1] + 8);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  *puVar12 = *local_a8;
  puVar12[1] = local_a8[1];
  puVar4 = (undefined8 *)param_1[1];
  puVar10 = (undefined8 *)*param_1;
  puVar6 = puVar15;
  local_98 = puVar12;
  if (param_2 == puVar4) {
    for (; local_90 = puVar6, puVar10 != puVar4; puVar10 = puVar10 + 2) {
      *local_90 = 0;
      local_90[1] = 0;
      *local_90 = *puVar10;
      local_90[1] = puVar10[1];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar6 = local_90 + 2;
    }
    ppuVar11 = &local_90;
    local_88 = local_90;
    local_80 = param_1;
  }
  else {
    for (; local_78 = puVar6, puVar10 != param_2; puVar10 = puVar10 + 2) {
      *local_78 = 0;
      local_78[1] = 0;
      *local_78 = *puVar10;
      local_78[1] = puVar10[1];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar6 = local_78 + 2;
    }
    local_70 = local_78;
    local_68 = param_1;
    FUN_18000a940((longlong *)&local_78);
    puVar4 = (undefined8 *)param_1[1];
    local_60 = puVar12 + 2;
    if (param_2 != puVar4) {
      puVar12 = (undefined8 *)((longlong)param_2 + (longlong)local_60 + (-0x10 - (longlong)puVar12))
      ;
      do {
        *local_60 = 0;
        local_60[1] = 0;
        *local_60 = *puVar12;
        local_60[1] = puVar12[1];
        local_60 = local_60 + 2;
        *puVar12 = 0;
        puVar12[1] = 0;
        puVar12 = puVar12 + 2;
      } while (puVar12 != puVar4);
    }
    ppuVar11 = &local_60;
    local_58 = local_60;
    local_50 = param_1;
  }
  FUN_18000a940((longlong *)ppuVar11);
  pvVar8 = (void *)*param_1;
  if (pvVar8 != (void *)0x0) {
    pvVar13 = (void *)param_1[1];
    if (pvVar8 != pvVar13) {
      do {
        lVar3 = *(longlong *)((longlong)pvVar8 + 8);
        if (lVar3 != 0) {
          LOCK();
          piVar1 = (int *)(lVar3 + 8);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
            LOCK();
            piVar1 = (int *)(lVar3 + 0xc);
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
            }
          }
        }
        pvVar8 = (void *)((longlong)pvVar8 + 0x10);
      } while (pvVar8 != pvVar13);
      pvVar8 = (void *)*param_1;
      uVar16 = local_a0;
    }
    pvVar13 = pvVar8;
    if ((0xfff < (param_1[2] - (longlong)pvVar8 & 0xfffffffffffffff0U)) &&
       (pvVar13 = *(void **)((longlong)pvVar8 + -8),
       0x1f < (ulonglong)((longlong)pvVar8 + (-8 - (longlong)pvVar13)))) {
LAB_18000aca3:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar13);
  }
  *param_1 = (longlong)puVar15;
  param_1[1] = (longlong)(puVar15 + uVar16 * 2);
  param_1[2] = (longlong)(puVar15 + uVar14 * 2);
  FUN_18000c7f0(local_48 ^ (ulonglong)auStack_c8);
  return;
}


/* Function 18000acc4 FUN_18000acc4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18000acc4(void)

{
  BOOL BVar1;
  undefined1 auStack_38 [32];
  int local_18 [2];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  BVar1 = InitOnceBeginInitialize((LPINIT_ONCE)&DAT_18001f608,0,local_18,(LPVOID *)0x0);
  if (BVar1 != 0) {
    if (local_18[0] != 0) {
      if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                  4) < DAT_18001f670) {
        _Init_thread_header(&DAT_18001f670);
        if (DAT_18001f670 == -1) {
          _DAT_18001f660 = 0;
          DAT_18001f668 = 0;
          atexit(FUN_180015930);
          _Init_thread_footer(&DAT_18001f670);
        }
      }
      DAT_18001f658 = &DAT_18001f660;
      BVar1 = InitOnceComplete((LPINIT_ONCE)&DAT_18001f608,0,(LPVOID)0x0);
      if (BVar1 == 0) goto LAB_18000ad95;
    }
    FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
    return;
  }
LAB_18000ad95:
                    /* WARNING: Subroutine does not return */
  abort();
}


/* Function 18000ad9c FUN_18000ad9c */

void FUN_18000ad9c(undefined8 *param_1)

{
  void *_Memory;
  void *pvVar1;
  
  _Memory = (void *)*param_1;
  if (_Memory != (void *)0x0) {
    pvVar1 = *(void **)((longlong)_Memory + 0x38);
    if (pvVar1 != (void *)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(pvVar1,pvVar1 != _Memory);
      *(undefined8 *)((longlong)_Memory + 0x38) = 0;
    }
    free(_Memory);
  }
  return;
}


/* Function 18000ade0 FUN_18000ade0 */

void FUN_18000ade0(longlong *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  
  if (param_1[7] == 0) {
    std::_Xbad_function_call();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  plVar1 = (longlong *)param_1[7];
  if (plVar1 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar1,plVar1 != param_1);
    param_1[7] = 0;
  }
  free(param_1);
  return;
}


/* Function 18000ae40 FUN_18000ae40 */

void FUN_18000ae40(longlong param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined ****ppppuVar3;
  undefined ***pppuVar4;
  longlong *plVar5;
  undefined ****ppppuVar6;
  longlong lVar7;
  undefined1 auStack_48 [32];
  undefined ***local_28;
  undefined ***local_20;
  longlong lStack_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_48;
  ppppuVar3 = (undefined ****)operator_new(0x40);
  ppppuVar3[7] = (undefined ***)0x0;
  local_28 = (undefined ***)ppppuVar3;
  local_20 = (undefined ***)ppppuVar3;
  if (*(longlong *)(param_1 + 0x38) != 0) {
    pppuVar4 = (undefined ***)
               (*(code *)PTR__guard_dispatch_icall_1800165a8)
                         (*(longlong *)(param_1 + 0x38),ppppuVar3);
    ppppuVar3[7] = pppuVar4;
  }
  if (param_2 == -1) {
    FUN_18000ade0((longlong *)ppppuVar3);
  }
  else {
    local_20 = (undefined ***)0x0;
    lStack_18 = 0;
    plVar5 = (longlong *)FUN_18000acc4();
    lVar7 = plVar5[1];
    if (lVar7 != 0) {
      LOCK();
      *(int *)(lVar7 + 8) = *(int *)(lVar7 + 8) + 1;
      UNLOCK();
      lVar7 = plVar5[1];
    }
    local_20 = (undefined ***)*plVar5;
    ppppuVar6 = (undefined ****)local_20;
    if ((undefined ****)local_20 == (undefined ****)0x0) {
      local_28 = (undefined ***)&PTR_FUN_18001e4a8;
      ppppuVar6 = &local_28;
    }
    lStack_18 = lVar7;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(ppppuVar6,FUN_18000ade0,ppppuVar3);
    if (lVar7 != 0) {
      LOCK();
      piVar1 = (int *)(lVar7 + 8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)();
        LOCK();
        piVar1 = (int *)(lVar7 + 0xc);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)();
        }
      }
    }
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_48);
  return;
}


/* Function 18000af70 FUN_18000af70 */

undefined8 * FUN_18000af70(longlong param_1,undefined8 *param_2)

{
  *param_2 = &PTR_FUN_18001e468;
  param_2[1] = *(undefined8 *)(param_1 + 8);
  return param_2;
}


/* Function 18000af90 FUN_18000af90 */

undefined8 * FUN_18000af90(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  
  *param_2 = &PTR_FUN_18001e438;
  param_2[1] = *(undefined8 *)(param_1 + 8);
  param_2[2] = 0;
  param_2[3] = 0;
  if (*(longlong *)(param_1 + 0x18) != 0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 8);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  param_2[2] = *(undefined8 *)(param_1 + 0x10);
  param_2[3] = *(undefined8 *)(param_1 + 0x18);
  return param_2;
}


/* Function 18000afd0 FUN_18000afd0 */

undefined8 * FUN_18000afd0(longlong param_1,undefined8 *param_2)

{
  *param_2 = &PTR_FUN_18001e438;
  param_2[1] = *(undefined8 *)(param_1 + 8);
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[2] = *(undefined8 *)(param_1 + 0x10);
  param_2[3] = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  return param_2;
}


/* Function 18000b010 FUN_18000b010 */

void FUN_18000b010(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_18000b914(*(longlong *)(param_1 + 0x10),*(undefined ***)(param_1 + 8),-1,param_4);
  return;
}


/* Function 18000b030 FUN_18000b030 */

TypeDescriptor * FUN_18000b030(void)

{
  return &<lambda_f25c37099038263181b5186a3fa41b37>::RTTI_Type_Descriptor;
}


/* Function 18000b040 FUN_18000b040 */

void FUN_18000b040(void *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)((longlong)param_1 + 0x18);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      LOCK();
      piVar1 = (int *)(lVar3 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      }
    }
  }
  if (param_2 != '\0') {
    free(param_1);
  }
  return;
}


/* Function 18000b0bc FUN_18000b0bc */

void FUN_18000b0bc(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  _ContextCallback *p_Var1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 auStack_108 [32];
  undefined4 local_e8;
  longlong local_e0;
  undefined ***local_d8;
  undefined **local_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined ***local_88;
  undefined1 *local_80;
  longlong local_78;
  undefined1 local_60 [56];
  undefined8 local_28;
  longlong local_20;
  longlong lStack_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_108;
  local_e8 = 0;
  local_20 = 0;
  lStack_18 = 0;
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(*param_1,&local_20);
  local_e0 = 0;
  local_e8 = 1;
  Concurrency::details::_ContextCallback::_Capture((_ContextCallback *)&local_e0);
  bVar5 = local_e0 == *(longlong *)(*param_1 + 0x10);
  Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)&local_e0);
  if (bVar5) {
    FUN_18000b914(local_20,(undefined **)*param_1,-1,param_4);
  }
  else {
    local_b8 = *param_1;
    p_Var1 = (_ContextCallback *)(local_b8 + 0x10);
    if (lStack_18 != 0) {
      LOCK();
      *(int *)(lStack_18 + 8) = *(int *)(lStack_18 + 8) + 1;
      UNLOCK();
    }
    local_c0 = &PTR_FUN_18001e438;
    local_b0 = local_20;
    local_a8 = lStack_18;
    local_88 = &local_c0;
    local_d8 = &local_c0;
    local_80 = local_60;
    local_28 = 0;
    local_78 = local_b8;
    local_28 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(&local_c0,local_60);
    Concurrency::details::_ContextCallback::_CallInContext(p_Var1,local_60,0);
    if (local_88 != (undefined ***)0x0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)
                (local_88,CONCAT71((int7)((ulonglong)&local_c0 >> 8),local_88 != &local_c0));
    }
  }
  lVar4 = lStack_18;
  if (lStack_18 != 0) {
    LOCK();
    piVar2 = (int *)(lStack_18 + 8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lStack_18);
      LOCK();
      piVar2 = (int *)(lVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
      }
    }
  }
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_108);
  return;
}


/* Function 18000b2a0 FUN_18000b2a0 */

void FUN_18000b2a0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_18000b0bc((longlong *)(param_1 + 8),param_2,param_3,param_4);
  return;
}


/* Function 18000b2b0 FUN_18000b2b0 */

TypeDescriptor * FUN_18000b2b0(void)

{
  return &<lambda_2fa3e3d11fb97352afa77a4a13bfb543>::RTTI_Type_Descriptor;
}


/* Function 18000b2b8 FUN_18000b2b8 */

void FUN_18000b2b8(longlong *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)param_1[7];
  if (plVar1 != (longlong *)0x0) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(plVar1,plVar1 != param_1);
    param_1[7] = 0;
  }
  return;
}


/* Function 18000b2e8 FUN_18000b2e8 */

void FUN_18000b2e8(undefined8 *param_1)

{
  undefined1 auStack_48 [32];
  char *local_28;
  undefined1 local_20;
  ulonglong local_18;
  
  local_18 = DAT_18001e100 ^ (ulonglong)auStack_48;
  local_20 = 1;
  *param_1 = std::exception::vftable;
  local_28 = "Fail to schedule the chore!";
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(&local_28);
  *param_1 = &PTR_FUN_18001e498;
  FUN_18000c7f0(local_18 ^ (ulonglong)auStack_48);
  return;
}


/* Function 18000b350 FUN_18000b350 */

undefined8 * FUN_18000b350(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = &PTR_FUN_18001e498;
  return param_1;
}


/* Function 18000b390 FUN_18000b390 */

_Threadpool_chore * FUN_18000b390(_Threadpool_chore *param_1)

{
  Concurrency::details::_Release_chore(param_1);
  free(param_1);
  return param_1;
}


/* Function 18000b3b8 FUN_18000b3b8 */

void FUN_18000b3b8(undefined8 *param_1)

{
  _Threadpool_chore *_Memory;
  
  _Memory = (_Threadpool_chore *)*param_1;
  if (_Memory != (_Threadpool_chore *)0x0) {
    Concurrency::details::_Release_chore(_Memory);
    free(_Memory);
  }
  return;
}


/* Function 18000b3f0 FUN_18000b3f0 */

void FUN_18000b3f0(_Threadpool_chore *param_1)

{
  undefined1 auStack_38 [32];
  _Threadpool_chore *local_18;
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18 = param_1;
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(*(undefined8 *)(param_1 + 0x20));
  Concurrency::details::_Release_chore(param_1);
  free(param_1);
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
  return;
}


/* Function 18000b450 FUN_18000b450 */

void FUN_18000b450(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  _Threadpool_chore *p_Var2;
  undefined8 local_28 [4];
  
  p_Var2 = (_Threadpool_chore *)operator_new(0x28);
  *(undefined8 *)p_Var2 = 0;
  *(undefined8 *)(p_Var2 + 8) = 0;
  *(undefined8 *)(p_Var2 + 0x10) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)p_Var2 = 0;
  *(code **)(p_Var2 + 8) = FUN_18000b3f0;
  *(_Threadpool_chore **)(p_Var2 + 0x10) = p_Var2;
  *(undefined8 *)(p_Var2 + 0x18) = param_2;
  *(undefined8 *)(p_Var2 + 0x20) = param_3;
  iVar1 = Concurrency::details::_Schedule_chore(p_Var2);
  if (iVar1 == 0) {
    return;
  }
  FUN_18000b390(p_Var2);
  FUN_18000b2e8(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001af78);
}


/* Function 18000b4f0 FUN_18000b4f0 */

/* WARNING: Switch with 1 destination removed at 0x00018000b51f */

void FUN_18000b4f0(longlong *param_1)

{
  (*(code *)PTR__guard_dispatch_icall_1800165a8)();
                    /* WARNING: Could not recover jumptable at 0x000180012b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)(param_1,1);
  return;
}


/* Function 18000b528 FUN_18000b528 */

void FUN_18000b528(_ExceptionHolder *param_1)

{
  void *pvVar1;
  code *pcVar2;
  void *_Memory;
  
  if (*(int *)param_1 == 0) {
    Concurrency::details::_ExceptionHolder::ReportUnhandledError(param_1);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pvVar1 = *(void **)(param_1 + 0x20);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (*(longlong *)(param_1 + 0x30) - (longlong)pvVar1 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000b596. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __ExceptionPtrDestroy(param_1 + 8);
  return;
}


/* Function 18000b5b0 FUN_18000b5b0 */

void FUN_18000b5b0(longlong param_1)

{
  FUN_18000b528((_ExceptionHolder *)(param_1 + 0x10));
  return;
}


/* Function 18000b5c0 FUN_18000b5c0 */

undefined8 * FUN_18000b5c0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &PTR_FUN_18001e4b0;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 18000b5ec FUN_18000b5ec */

void FUN_18000b5ec(undefined8 *param_1)

{
  longlong *plVar1;
  void *pvVar2;
  void *_Memory;
  
  plVar1 = (longlong *)*param_1;
  if ((plVar1 != (longlong *)0x0) && (pvVar2 = (void *)*plVar1, pvVar2 != (void *)0x0)) {
    _Memory = pvVar2;
    if ((0xfff < (plVar1[2] - (longlong)pvVar2 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *plVar1 = 0;
    plVar1[1] = 0;
    plVar1[2] = 0;
  }
  return;
}


/* Function 18000b650 FUN_18000b650 */

undefined8 * FUN_18000b650(undefined8 *param_1,undefined8 *param_2)

{
  void *_Src;
  code *pcVar1;
  void *pvVar2;
  void *pvVar3;
  undefined8 *puVar4;
  size_t _Size;
  ulonglong uVar5;
  undefined8 *local_28 [2];
  
  *param_1 = *param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  _Src = (void *)param_2[1];
  if (_Src != (void *)param_2[2]) {
    _Size = (longlong)param_2[2] - (longlong)_Src;
    uVar5 = (longlong)_Size >> 3;
    local_28[0] = param_1;
    if (0x1fffffffffffffff < uVar5) {
LAB_18000b749:
      FUN_180001488();
      pcVar1 = (code *)swi(3);
      puVar4 = (undefined8 *)(*pcVar1)();
      return puVar4;
    }
    uVar5 = uVar5 * 8;
    if (uVar5 < 0x1000) {
      if (uVar5 == 0) {
        pvVar3 = (void *)0x0;
      }
      else {
        pvVar3 = operator_new(uVar5);
      }
    }
    else {
      if (uVar5 + 0x27 <= uVar5) goto LAB_18000b749;
      pvVar2 = operator_new(uVar5 + 0x27);
      if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      pvVar3 = (void *)((longlong)pvVar2 + 0x27U & 0xffffffffffffffe0);
      *(void **)((longlong)pvVar3 - 8) = pvVar2;
    }
    param_1[1] = pvVar3;
    param_1[2] = pvVar3;
    param_1[3] = (void *)((longlong)pvVar3 + uVar5);
    pvVar3 = (void *)param_1[1];
    memmove(pvVar3,_Src,_Size);
    local_28[0] = (undefined8 *)0x0;
    param_1[2] = (void *)(uVar5 + (longlong)pvVar3);
    FUN_18000b5ec(local_28);
  }
  return param_1;
}


/* Function 18000b750 FUN_18000b750 */

void FUN_18000b750(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 8);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (*(longlong *)(param_1 + 0x18) - (longlong)pvVar1 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  return;
}


/* Function 18000b7b0 FUN_18000b7b0 */

undefined1 FUN_18000b7b0(longlong *param_1,void *param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  void *_Memory;
  undefined8 *local_58;
  undefined8 *puStack_50;
  undefined8 *local_48;
  undefined8 *local_40;
  undefined8 local_38;
  void *local_30;
  longlong local_20;
  
  FUN_18000b650(&local_38,param_1 + 0x28);
  puVar5 = (undefined8 *)operator_new(0x48);
  *puVar5 = 0;
  puVar5[1] = 0;
  *(undefined4 *)(puVar5 + 1) = 1;
  *(undefined4 *)((longlong)puVar5 + 0xc) = 1;
  *puVar5 = &PTR_FUN_18001e4b0;
  puVar1 = puVar5 + 2;
  *(undefined4 *)puVar1 = 0;
  local_48 = puVar5;
  local_40 = puVar1;
  __ExceptionPtrCopy(puVar5 + 3,param_2);
  FUN_18000b650(puVar5 + 5,&local_38);
  local_58 = puVar1;
  puStack_50 = puVar5;
  uVar4 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,1,1,0,&local_58);
  puVar1 = puStack_50;
  if (puStack_50 != (undefined8 *)0x0) {
    LOCK();
    piVar2 = (int *)(puStack_50 + 1);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(puStack_50);
      LOCK();
      piVar2 = (int *)((longlong)puVar1 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar1);
      }
    }
  }
  if (local_30 != (void *)0x0) {
    _Memory = local_30;
    if ((0xfff < (local_20 - (longlong)local_30 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)local_30 + -8),
       0x1f < (ulonglong)((longlong)local_30 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  return uVar4;
}


/* Function 18000b914 FUN_18000b914 */

void FUN_18000b914(longlong param_1,undefined **param_2,int param_3,undefined8 param_4)

{
  undefined **local_18 [2];
  
  if (param_3 == -1) {
    local_18[0] = param_2;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_2);
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_2,1);
  }
  else if (*(longlong *)(param_1 + 0x130) == 0) {
    local_18[0] = &PTR_FUN_18001e4a8;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_18,FUN_18000b4f0,param_2,param_4,param_1);
  }
  else {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)();
  }
  return;
}


/* Function 18000b9a4 FUN_18000b9a4 */

void FUN_18000b9a4(_ContextCallback *param_1)

{
  Concurrency::details::_ContextCallback::_Reset(param_1);
  return;
}


/* Function 18000b9b4 FUN_18000b9b4 */

void FUN_18000b9b4(longlong param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  int *piVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  longlong lVar4;
  undefined7 uVar5;
  int iVar6;
  undefined1 auStack_a8 [32];
  longlong *local_88;
  undefined **local_78;
  undefined **local_70;
  undefined ***local_40;
  longlong local_38;
  longlong lStack_30;
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStack_a8;
  ppuVar2 = *(undefined ***)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  while (ppuVar2 != (undefined **)0x0) {
    ppuVar3 = (undefined **)ppuVar2[1];
    local_38 = 0;
    lStack_30 = 0;
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(ppuVar2,&local_38);
    lVar4 = local_38;
    if ((*(int *)(param_1 + 8) == 4) && (*(char *)(ppuVar2 + 4) == '\0')) {
      local_88 = (longlong *)(param_1 + 0x10);
      lVar4 = *local_88;
      if (lVar4 == 0) {
        local_88 = (longlong *)(local_38 + 0x10);
        param_4 = 0;
        uVar5 = (undefined7)((ulonglong)local_88 >> 8);
      }
      else {
        param_4 = CONCAT71((int7)((ulonglong)param_4 >> 8),1);
        uVar5 = (undefined7)((ulonglong)local_88 >> 8);
      }
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(local_38,CONCAT71(uVar5,1),lVar4 != 0);
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(ppuVar2,1);
    }
    else {
      Concurrency::details::_TaskEventLogger::_LogScheduleTask
                ((_TaskEventLogger *)(local_38 + 0x160),true);
      iVar6 = *(int *)((longlong)ppuVar2 + 0x24);
      if (ppuVar2[2] == (undefined *)0x0) {
        FUN_18000b914(lVar4,ppuVar2,iVar6,param_4);
      }
      else {
        if (iVar6 != -1) {
          *(undefined4 *)((longlong)ppuVar2 + 0x24) = 0x10;
          iVar6 = 0x10;
        }
        local_78 = &PTR_FUN_18001e468;
        local_40 = &local_78;
        local_70 = ppuVar2;
        FUN_18000ae40((longlong)&local_78,iVar6);
        if (local_40 != (undefined ***)0x0) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)
                    (local_40,CONCAT71((int7)((ulonglong)&local_78 >> 8),local_40 != &local_78));
        }
      }
    }
    lVar4 = lStack_30;
    ppuVar2 = ppuVar3;
    if (lStack_30 != 0) {
      LOCK();
      piVar1 = (int *)(lStack_30 + 8);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lStack_30);
        LOCK();
        piVar1 = (int *)(lVar4 + 0xc);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
        }
      }
    }
  }
  FUN_18000c7f0(local_28 ^ (ulonglong)auStack_a8);
  return;
}


/* Function 18000bb78 FUN_18000bb78 */

void FUN_18000bb78(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  
  uVar3 = (undefined1)param_2;
  uVar4 = (undefined7)((ulonglong)param_2 >> 8);
  *(undefined1 *)(param_1 + 0x170) = uVar3;
  iVar2 = _Mtx_lock(param_1 + 0x20);
  if (iVar2 != 0) {
    std::_Throw_C_error(iVar2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(int *)(param_1 + 8) == 4) {
    _Mtx_unlock();
  }
  else {
    *(undefined4 *)(param_1 + 8) = 3;
    _Mtx_unlock(param_1 + 0x20);
    iVar2 = _Mtx_lock(param_1 + 0xd0);
    if (iVar2 != 0) {
      std::_Throw_C_error(iVar2);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(int *)(param_1 + 0x138) < 2) {
      *(undefined4 *)(param_1 + 0x138) = 2;
    }
    _Cnd_broadcast(param_1 + 0x88);
    _Mtx_unlock(param_1 + 0xd0);
    FUN_18000b9b4(param_1,CONCAT71(uVar4,uVar3),param_3,param_4);
  }
  return;
}


/* Function 18000bc28 FUN_18000bc28 */

void FUN_18000bc28(longlong *param_1,longlong *param_2,longlong *param_3,undefined8 param_4)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  undefined7 uVar6;
  int iVar7;
  undefined1 uVar8;
  undefined7 uVar9;
  
  uVar8 = (undefined1)param_4;
  uVar9 = (undefined7)((ulonglong)param_4 >> 8);
  iVar7 = 0;
  lVar2 = *param_1;
  plVar5 = param_2;
  iVar4 = _Mtx_lock(lVar2 + 0x18);
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  plVar3 = (longlong *)*param_1;
  if (plVar3[0xe] == 0) {
    if ((char)plVar3[0x10] == '\0') {
      plVar5 = (longlong *)plVar3[1];
      if (plVar5 == (longlong *)plVar3[2]) {
        param_3 = param_2;
        FUN_18000a9b4(plVar3,plVar5,param_2);
      }
      else {
        *plVar5 = 0;
        plVar5[1] = 0;
        if (param_2[1] != 0) {
          LOCK();
          piVar1 = (int *)(param_2[1] + 8);
          *piVar1 = *piVar1 + 1;
          UNLOCK();
        }
        *plVar5 = *param_2;
        plVar5[1] = param_2[1];
        plVar3[1] = plVar3[1] + 0x10;
      }
    }
    else {
      iVar7 = 1;
    }
  }
  else {
    iVar7 = 2;
  }
  _Mtx_unlock(lVar2 + 0x18);
  uVar6 = (undefined7)((ulonglong)plVar5 >> 8);
  if (iVar7 == 1) {
    FUN_18000bb78(*param_2,CONCAT71(uVar6,*(undefined1 *)(*param_1 + 0x68)),param_3,
                  CONCAT71(uVar9,uVar8));
  }
  else if (iVar7 == 2) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)
              (*param_2,CONCAT71(uVar6,1),CONCAT71((int7)((ulonglong)(*param_1 + 0x70) >> 8),1),1,
               *param_1 + 0x70);
  }
  return;
}


/* Function 18000bd28 FUN_18000bd28 */

longlong * FUN_18000bd28(longlong *param_1,longlong *param_2,longlong *param_3,undefined8 param_4)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  void *pvVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *_Size;
  void *_Dst;
  bool bVar10;
  undefined8 unaff_retaddr;
  longlong local_f8;
  longlong lStack_f0;
  longlong local_e8;
  longlong local_e0;
  longlong lStack_d8;
  longlong local_d0;
  longlong local_c8;
  longlong lStack_c0;
  longlong *local_b8;
  longlong *local_b0;
  undefined8 local_a8;
  void *pvStack_a0;
  undefined8 local_98;
  longlong lStack_90;
  longlong *local_88;
  longlong *local_80;
  longlong local_78;
  longlong local_70;
  longlong lStack_68;
  longlong local_60;
  undefined8 local_58;
  void *local_50;
  longlong local_40;
  
  *param_1 = 0;
  param_1[1] = 0;
  lStack_f0 = param_3[1];
  if (lStack_f0 != 0) {
    LOCK();
    *(int *)(lStack_f0 + 8) = *(int *)(lStack_f0 + 8) + 1;
    UNLOCK();
    lStack_f0 = param_3[1];
  }
  local_f8 = *param_3;
  local_e8 = param_3[2];
  local_b0 = &local_f8;
  lVar4 = param_3[3];
  if (lVar4 == 0) {
    lVar9 = 2;
  }
  else {
    LOCK();
    *(int *)(lVar4 + 8) = *(int *)(lVar4 + 8) + 1;
    UNLOCK();
    lVar9 = lVar4;
  }
  if (lStack_f0 != 0) {
    LOCK();
    *(int *)(lStack_f0 + 8) = *(int *)(lStack_f0 + 8) + 1;
    UNLOCK();
  }
  local_e0 = local_f8;
  lStack_d8 = lStack_f0;
  local_d0 = local_e8;
  local_b8 = param_2;
  local_88 = param_1;
  local_80 = param_2;
  local_78 = lVar4;
  puVar6 = (undefined8 *)operator_new(0x1c8);
  *puVar6 = 0;
  puVar6[1] = 0;
  *(undefined4 *)(puVar6 + 1) = 1;
  *(undefined4 *)((longlong)puVar6 + 0xc) = 1;
  *puVar6 = &PTR_FUN_18001e388;
  if (lStack_d8 != 0) {
    LOCK();
    *(int *)(lStack_d8 + 8) = *(int *)(lStack_d8 + 8) + 1;
    UNLOCK();
  }
  local_70 = local_e0;
  lStack_68 = lStack_d8;
  local_60 = local_d0;
  plVar8 = &local_70;
  FUN_18000a134(puVar6 + 2,lVar9,plVar8);
  lVar5 = lStack_d8;
  if (lStack_d8 != 0) {
    LOCK();
    piVar1 = (int *)(lStack_d8 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lStack_d8);
      LOCK();
      piVar1 = (int *)(lVar5 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      }
    }
  }
  *param_1 = (longlong)(puVar6 + 2);
  lVar5 = param_1[1];
  param_1[1] = (longlong)puVar6;
  if (lVar5 != 0) {
    LOCK();
    piVar1 = (int *)(lVar5 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      LOCK();
      piVar1 = (int *)(lVar5 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar5);
      }
    }
  }
  if (lVar9 != 2) {
    lVar9 = *param_1;
    local_c8 = 0;
    lStack_c0 = 0;
    lVar5 = param_1[1];
    if (lVar5 != 0) {
      LOCK();
      *(int *)(lVar5 + 0xc) = *(int *)(lVar5 + 0xc) + 1;
      UNLOCK();
      local_c8 = lVar9;
      lStack_c0 = lVar5;
    }
    FUN_18000a524(lVar9,&local_c8);
  }
  lVar9 = lStack_f0;
  if (lStack_f0 != 0) {
    LOCK();
    piVar1 = (int *)(lStack_f0 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lStack_f0);
      LOCK();
      piVar1 = (int *)(lVar9 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar9);
      }
    }
  }
  if (lVar4 != 0) {
    LOCK();
    piVar1 = (int *)(lVar4 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
    }
  }
  bVar10 = (char)param_3[6] == '\0';
  if (bVar10) {
    pvStack_a0 = (void *)0x0;
    local_98 = 0;
    lStack_90 = 0;
    puVar6 = &local_a8;
  }
  else {
    puVar6 = FUN_18000b650(&local_58,param_3 + 7);
    unaff_retaddr = *puVar6;
  }
  lVar9 = lStack_90;
  lVar4 = *param_1;
  *(undefined8 *)(lVar4 + 0x140) = unaff_retaddr;
  plVar2 = (longlong *)(lVar4 + 0x148);
  if (plVar2 != puVar6 + 1) {
    pvVar7 = (void *)puVar6[1];
    _Size = (longlong *)(puVar6[2] - (longlong)pvVar7);
    _Dst = (void *)*plVar2;
    if ((ulonglong)(*(longlong *)(lVar4 + 0x158) - (longlong)_Dst >> 3) <
        (ulonglong)((longlong)_Size >> 3)) {
      FUN_18000a83c(plVar2,(longlong)_Size >> 3);
      _Dst = (void *)*plVar2;
    }
    plVar8 = _Size;
    memmove(_Dst,pvVar7,(size_t)_Size);
    *(longlong *)(lVar4 + 0x150) = (longlong)_Size + (longlong)_Dst;
  }
  if ((bVar10) && (pvStack_a0 != (void *)0x0)) {
    pvVar7 = pvStack_a0;
    if ((0xfff < (ulonglong)((lVar9 - (longlong)pvStack_a0 >> 3) * 8)) &&
       (pvVar7 = *(void **)((longlong)pvStack_a0 + -8),
       0x1f < (ulonglong)((longlong)pvStack_a0 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar7);
  }
  if ((!bVar10) && (local_50 != (void *)0x0)) {
    pvVar7 = local_50;
    if ((0xfff < (ulonglong)((local_40 - (longlong)local_50 >> 3) * 8)) &&
       (pvVar7 = *(void **)((longlong)local_50 + -8),
       0x1f < (ulonglong)((longlong)local_50 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar7);
  }
  plVar2 = local_b8;
  FUN_18000bc28(local_b8,param_1,plVar8,param_4);
  lVar4 = plVar2[1];
  if (lVar4 != 0) {
    LOCK();
    piVar1 = (int *)(lVar4 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
      LOCK();
      piVar1 = (int *)(lVar4 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar4);
      }
    }
  }
  return param_1;
}


/* Function 18000c138 FUN_18000c138 */

void FUN_18000c138(longlong *param_1,longlong *param_2,longlong *param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong unaff_retaddr;
  undefined1 auStack_88 [32];
  longlong local_68;
  longlong lStack_60;
  longlong *local_58;
  longlong local_48 [3];
  longlong *local_30;
  ulonglong local_28;
  
  local_28 = DAT_18001e100 ^ (ulonglong)auStack_88;
  *(undefined1 *)(param_3 + 6) = 1;
  param_3[7] = unaff_retaddr;
  if (param_3 + 8 != local_48) {
    param_3[9] = param_3[8];
  }
  *param_1 = 0;
  param_1[1] = 0;
  lStack_60 = param_2[1];
  if (lStack_60 != 0) {
    LOCK();
    *(int *)(lStack_60 + 8) = *(int *)(lStack_60 + 8) + 1;
    UNLOCK();
    lStack_60 = param_2[1];
  }
  local_68 = *param_2;
  local_58 = param_2;
  local_30 = param_3;
  FUN_18000bd28(param_1,&local_68,param_3,param_4);
  lVar3 = param_2[1];
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      LOCK();
      piVar1 = (int *)(lVar3 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      }
    }
  }
  FUN_1800099c0((longlong)param_3);
  FUN_18000c7f0(local_28 ^ (ulonglong)auStack_88);
  return;
}


/* Function 18000c230 FUN_18000c230 */

undefined8 * FUN_18000c230(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &PTR_FUN_18001e520;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 18000c268 FUN_18000c268 */

void FUN_18000c268(undefined8 *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)param_1[0x20];
  (*(code *)PTR__guard_dispatch_icall_1800165a8)(puVar1,0);
  if (puVar1 != param_1) {
    Platform::Details::Heap::Free(puVar1);
  }
  return;
}


/* Function 18000c2a8 FUN_18000c2a8 */

bool FUN_18000c2a8(void)

{
  int iVar1;
  
  iVar1 = WindowsIsStringEmpty();
  return iVar1 != 0;
}


/* Function 18000c2bc FUN_18000c2bc */

void FUN_18000c2bc(undefined8 param_1)

{
  undefined1 auStack_38 [32];
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = DAT_18001e100 ^ (ulonglong)auStack_38;
  local_18[0] = 0;
  WindowsCompareStringOrdinal(param_1,0,local_18);
  FUN_18000c7f0(local_10 ^ (ulonglong)auStack_38);
  return;
}


/* Function 18000c2fc FUN_18000c2fc */

undefined8 * FUN_18000c2fc(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  uVar1 = param_2[2];
  if (7 < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  lVar2 = param_1[2];
  if ((ulonglong)(param_1[3] - lVar2) < uVar1) {
    param_1 = FUN_1800042bc(param_1,uVar1,param_3,param_2,uVar1);
  }
  else {
    param_1[2] = uVar1 + lVar2;
    puVar3 = param_1;
    if (7 < (ulonglong)param_1[3]) {
      puVar3 = (undefined8 *)*param_1;
    }
    memmove((void *)((longlong)puVar3 + lVar2 * 2),param_2,uVar1 * 2);
    *(undefined2 *)((longlong)puVar3 + (uVar1 + lVar2) * 2) = 0;
  }
  return param_1;
}


/* Function 18000c380 Initialize */

/* Library Function - Single Match
    int __cdecl Platform::Details::Initialize(void)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl Platform::Details::Initialize(void)

{
  long lVar1;
  
  if (DAT_18001eee8 == 3) {
    DAT_18001eee8 = 0;
  }
  lVar1 = Platform::Details::InitializeData(DAT_18001eee8);
  if (lVar1 < 0) {
    Platform::Details::UninitializeData(DAT_18001eee8);
  }
  else {
    atexit(FUN_18000c4e0);
    lVar1 = 0;
  }
  return lVar1;
}


/* Function 18000c3e0 FUN_18000c3e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_18000c3e0(void)

{
  DAT_18001ef28 = 1;
  DAT_18001ef08 = &DAT_18001ef18;
  DAT_18001ef18 = Platform::Details::InProcModule::vftable;
  _DAT_18001ef20 = Platform::Details::InProcModule::vftable;
  DAT_18001eee0 = &DAT_18001ef20;
  return 1;
}


/* Function 18000c430 FID_conflict:`scalar_deleting_destructor' */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __ptr64 __cdecl Microsoft::WRL::Module<1,class
   Platform::Details::InProcModule>::`scalar deleting destructor'(unsigned int) __ptr64
    public: virtual void * __ptr64 __cdecl Microsoft::WRL::Module<5,class
   Platform::Details::InProcModule>::`scalar deleting destructor'(unsigned int) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ModuleBase * FID_conflict__scalar_deleting_destructor_(ModuleBase *param_1,uint param_2)

{
  *(undefined ***)param_1 = Microsoft::WRL::Module<1,class_Platform::Details::InProcModule>::vftable
  ;
  Microsoft::WRL::Details::TerminateMap(param_1,(wchar_t *)0x0,true);
  DAT_18001ef08 = 0;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 18000c480 `scalar_deleting_destructor' */

/* Library Function - Single Match
    public: virtual void * __ptr64 __cdecl Platform::Details::InProcModule::`scalar deleting
   destructor'(unsigned int) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __thiscall
Platform::Details::InProcModule::_scalar_deleting_destructor_(InProcModule *this,uint param_1)

{
  *(undefined ***)(this + 8) = vftable;
  DAT_18001eee0 = 0;
  *(undefined ***)this = Microsoft::WRL::Module<1,class_Platform::Details::InProcModule>::vftable;
  Microsoft::WRL::Details::TerminateMap((ModuleBase *)this,(wchar_t *)0x0,true);
  DAT_18001ef08 = 0;
  if ((param_1 & 1) != 0) {
    free(this);
  }
  return this;
}


/* Function 18000c4e0 FUN_18000c4e0 */

void FUN_18000c4e0(void)

{
  Platform::Details::UninitializeData(DAT_18001eee8);
  return;
}


/* Function 18000c4f0 FUN_18000c4f0 */

int FUN_18000c4f0(void)

{
  int iVar1;
  
  iVar1 = DAT_18001ef00;
  LOCK();
  DAT_18001ef00 = DAT_18001ef00 + -1;
  UNLOCK();
  return iVar1 + -1;
}


/* Function 18000c500 FUN_18000c500 */

undefined * FUN_18000c500(void)

{
  return &DAT_18001b010;
}


/* Function 18000c510 FUN_18000c510 */

undefined * FUN_18000c510(void)

{
  return &DAT_18001b028;
}


/* Function 18000c520 FUN_18000c520 */

undefined * FUN_18000c520(void)

{
  return &DAT_18001eef8;
}


/* Function 18000c530 FUN_18000c530 */

undefined * FUN_18000c530(void)

{
  return &DAT_18001b018;
}


/* Function 18000c540 FUN_18000c540 */

undefined4 FUN_18000c540(void)

{
  return DAT_18001ef00;
}


/* Function 18000c550 FUN_18000c550 */

int FUN_18000c550(void)

{
  int iVar1;
  
  iVar1 = DAT_18001ef00;
  LOCK();
  DAT_18001ef00 = DAT_18001ef00 + 1;
  UNLOCK();
  return iVar1 + 1;
}


/* Function 18000c560 FUN_18000c560 */

undefined8 FUN_18000c560(void)

{
  return 0x80004001;
}


/* Function 18000c568 TerminateMap */

/* Library Function - Single Match
    bool __cdecl Microsoft::WRL::Details::TerminateMap(class Microsoft::WRL::Details::ModuleBase *
   __ptr64,wchar_t const * __ptr64,bool)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __cdecl
Microsoft::WRL::Details::TerminateMap(ModuleBase *param_1,wchar_t *param_2,bool param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  PSRWLOCK SRWLock;
  PVOID pvVar6;
  short *psVar7;
  longlong lVar8;
  
  plVar4 = (longlong *)(*(code *)PTR__guard_dispatch_icall_1800165a8)();
  plVar5 = (longlong *)(*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1);
LAB_18000c5b5:
  do {
    plVar4 = plVar4 + 1;
    if (plVar5 <= plVar4) {
      iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1);
      return iVar3 == 0;
    }
  } while (*plVar4 == 0);
  if (param_2 != (wchar_t *)0x0) goto code_r0x00018000c5cc;
  goto LAB_18000c5fb;
code_r0x00018000c5cc:
  psVar7 = *(short **)(*plVar4 + 0x20);
  if (psVar7 != (short *)0x0) {
    lVar8 = (longlong)param_2 - (longlong)psVar7;
    do {
      sVar1 = *psVar7;
      sVar2 = *(short *)((longlong)psVar7 + lVar8);
      if (sVar1 != sVar2) break;
      psVar7 = psVar7 + 1;
    } while (sVar2 != 0);
    if (sVar1 == sVar2) {
LAB_18000c5fb:
      iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1);
      if ((iVar3 != 0) && (!param_3)) {
        return false;
      }
      if (**(longlong **)(*plVar4 + 0x18) != 0) {
        SRWLock = (PSRWLOCK)(*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1);
        AcquireSRWLockExclusive(SRWLock);
        pvVar6 = (PVOID)**(undefined8 **)(*plVar4 + 0x18);
        if (pvVar6 == (PVOID)0x0) {
          if (SRWLock != (PSRWLOCK)0x0) {
            ReleaseSRWLockExclusive(SRWLock);
          }
        }
        else {
          **(undefined8 **)(*plVar4 + 0x18) = 0;
          if (SRWLock != (PSRWLOCK)0x0) {
            ReleaseSRWLockExclusive(SRWLock);
          }
          pvVar6 = DecodePointer(pvVar6);
          (*(code *)PTR__guard_dispatch_icall_1800165a8)(pvVar6);
        }
      }
    }
  }
  goto LAB_18000c5b5;
}


/* Function 18000c6d4 GetIidsFn */

long __cdecl GetIidsFn(int param_1,ulong *param_2,__s_GUID *param_3,Guid **param_4)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c6f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetIidsFn(param_1,param_2,param_3,param_4);
  return lVar1;
}


/* Function 18000c6dc WindowsCreateString */

void WindowsCreateString(void)

{
  WindowsCreateString();
  return;
}


/* Function 18000c6e4 GetActivationFactoryByPCWSTR */

long __cdecl GetActivationFactoryByPCWSTR(void *param_1,Guid *param_2,void **param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c6fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetActivationFactoryByPCWSTR(param_1,param_2,param_3);
  return lVar1;
}


/* Function 18000c6e9 InitializeData */

long __cdecl Platform::Details::InitializeData(int param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c6e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = InitializeData(param_1);
  return lVar1;
}


/* Function 18000c6ef UninitializeData */

void __cdecl Platform::Details::UninitializeData(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c6ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UninitializeData(param_1);
  return;
}


/* Function 18000c6f5 GetIidsFn */

long __cdecl GetIidsFn(int param_1,ulong *param_2,__s_GUID *param_3,Guid **param_4)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c6f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetIidsFn(param_1,param_2,param_3,param_4);
  return lVar1;
}


/* Function 18000c6fb GetActivationFactoryByPCWSTR */

long __cdecl GetActivationFactoryByPCWSTR(void *param_1,Guid *param_2,void **param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c6fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = GetActivationFactoryByPCWSTR(param_1,param_2,param_3);
  return lVar1;
}


/* Function 18000c704 _Facet_Register */

/* Library Function - Single Match
    void __cdecl std::_Facet_Register(class std::_Facet_base * __ptr64)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl std::_Facet_Register(_Facet_base *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)operator_new(0x10);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = DAT_18001ef30;
    puVar1[1] = param_1;
  }
  DAT_18001ef30 = puVar1;
  return;
}


/* Function 18000c750 _Unlock */

void __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Unlock
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Unlock(this);
  return;
}


/* Function 18000c760 _Lock */

void __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Lock
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Lock(this);
  return;
}


/* Function 18000c770 sync */

int __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sync
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = sync(this);
  return iVar1;
}


/* Function 18000c780 xsputn */

__int64 __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::xsputn
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this,wchar_t *param_1,
          __int64 param_2)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = xsputn(this,param_1,param_2);
  return _Var1;
}


/* Function 18000c790 showmanyc */

__int64 __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::showmanyc
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = showmanyc(this);
  return _Var1;
}


/* Function 18000c7a0 uflow */

ushort __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::uflow
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this)

{
  ushort uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c7a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = uflow(this);
  return uVar1;
}


/* Function 18000c7b0 xsgetn */

__int64 __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::xsgetn
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this,wchar_t *param_1,
          __int64 param_2)

{
  __int64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c7b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = xsgetn(this,param_1,param_2);
  return _Var1;
}


/* Function 18000c7c0 setbuf */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setbuf
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this,wchar_t *param_1,
          __int64 param_2)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000c7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pbVar1 = setbuf(this,param_1,param_2);
  return pbVar1;
}


/* Function 18000c7d0 imbue */

void __thiscall
std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::imbue
          (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this,locale *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018000c7d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  imbue(this,param_1);
  return;
}


/* Function 18000c7f0 FUN_18000c7f0 */

void FUN_18000c7f0(longlong param_1)

{
  if ((param_1 == DAT_18001e100) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  FUN_18000d090();
  return;
}


/* Function 18000c810 free */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d42c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}


/* Function 18000c820 FUN_18000c820 */

undefined8 * FUN_18000c820(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* Function 18000c84c operator_new */

/* Library Function - Single Match
    void * __ptr64 __cdecl operator new(unsigned __int64)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __cdecl operator_new(__uint64 param_1)

{
  code *pcVar1;
  int iVar2;
  void *pvVar3;
  
  do {
    pvVar3 = malloc(param_1);
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
    iVar2 = _callnewh(param_1);
  } while (iVar2 != 0);
  if (param_1 == 0xffffffffffffffff) {
    FUN_180001488();
    pcVar1 = (code *)swi(3);
    pvVar3 = (void *)(*pcVar1)();
    return pvVar3;
  }
  FUN_18000d0a8();
  pcVar1 = (code *)swi(3);
  pvVar3 = (void *)(*pcVar1)();
  return pvVar3;
}


/* Function 18000c888 FUN_18000c888 */

void FUN_18000c888(undefined4 *param_1)

{
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18001ef48);
  *param_1 = 0;
  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18001ef48);
                    /* WARNING: Could not recover jumptable at 0x00018000c8ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WakeAllConditionVariable(&DAT_18001ef40);
  return;
}


/* Function 18000c8c4 _Init_thread_footer */

/* Library Function - Single Match
    _Init_thread_footer
   
   Library: Visual Studio 2019 Release */

void _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18001ef48);
  uVar1 = (ulonglong)_tls_index;
  DAT_18001e0f0 = DAT_18001e0f0 + 1;
  *param_1 = DAT_18001e0f0;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = DAT_18001e0f0;
  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18001ef48);
                    /* WARNING: Could not recover jumptable at 0x00018000c926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WakeAllConditionVariable(&DAT_18001ef40);
  return;
}


/* Function 18000c930 _Init_thread_header */

/* Library Function - Single Match
    _Init_thread_header
   
   Library: Visual Studio 2019 Release */

void _Init_thread_header(int *param_1)

{
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_18001ef48);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_18000c995:
                    /* WARNING: Could not recover jumptable at 0x00018000c9a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_18001ef48);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           DAT_18001e0f0;
      goto LAB_18000c995;
    }
    SleepConditionVariableSRW((PCONDITION_VARIABLE)&DAT_18001ef40,(PSRWLOCK)&DAT_18001ef48,100,0);
  } while( true );
}


/* Function 18000c9a8 __scrt_acquire_startup_lock */

/* Library Function - Single Match
    __scrt_acquire_startup_lock
   
   Library: Visual Studio 2019 Release */

ulonglong __scrt_acquire_startup_lock(void)

{
  ulonglong uVar1;
  bool bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  bVar2 = __scrt_is_ucrt_dll_in_use();
  uVar3 = CONCAT71(extraout_var,bVar2);
  if ((int)uVar3 == 0) {
LAB_18000c9d6:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_18001ef58 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_18001ef58;
        uVar1 = DAT_18001ef58;
      }
      DAT_18001ef58 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_18000c9d6;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}


/* Function 18000c9e4 __scrt_dllmain_after_initialize_c */

/* Library Function - Single Match
    __scrt_dllmain_after_initialize_c
   
   Library: Visual Studio 2019 Release */

undefined8 __scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar3 = FUN_18000d26c();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = __isa_available_init();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}


/* Function 18000ca18 __scrt_dllmain_before_initialize_c */

/* Library Function - Single Match
    __scrt_dllmain_before_initialize_c
   
   Library: Visual Studio 2019 Release */

bool __scrt_dllmain_before_initialize_c(void)

{
  undefined8 uVar1;
  
  uVar1 = __scrt_initialize_onexit_tables(0);
  return (char)uVar1 != '\0';
}


/* Function 18000ca30 FUN_18000ca30 */

undefined1 FUN_18000ca30(void)

{
  char cVar1;
  
  cVar1 = FUN_1800099bc();
  if (cVar1 != '\0') {
    cVar1 = FUN_1800099bc();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_1800099bc();
  }
  return 0;
}


/* Function 18000ca58 FUN_18000ca58 */

undefined1 FUN_18000ca58(void)

{
  FUN_1800099bc();
  FUN_1800099bc();
  return 1;
}


/* Function 18000ca70 __scrt_dllmain_exception_filter */

/* Library Function - Single Match
    __scrt_dllmain_exception_filter
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_dllmain_exception_filter
               (undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,
               undefined4 param_5,undefined8 param_6)

{
  bool bVar1;
  undefined7 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) && (param_2 == 1)) {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}


/* Function 18000cad0 __scrt_dllmain_uninitialize_c */

/* Library Function - Single Match
    __scrt_dllmain_uninitialize_c
   
   Library: Visual Studio 2019 Release */

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _execute_onexit_table(&DAT_18001ef68);
    return;
  }
  uVar2 = FUN_180001a40();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}


/* Function 18000cb00 __scrt_dllmain_uninitialize_critical */

/* Library Function - Single Match
    __scrt_dllmain_uninitialize_critical
   
   Library: Visual Studio 2019 Release */

void __scrt_dllmain_uninitialize_critical(void)

{
  FUN_1800099bc();
  FUN_1800099bc();
  return;
}


/* Function 18000cb14 __scrt_initialize_crt */

/* Library Function - Single Match
    __scrt_initialize_crt
   
   Library: Visual Studio 2019 Release */

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_18001ef60 = 1;
  }
  __isa_available_init();
  cVar1 = FUN_1800099bc();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_1800099bc();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_1800099bc();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}


/* Function 18000cb60 __scrt_initialize_onexit_tables */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __scrt_initialize_onexit_tables
   
   Library: Visual Studio 2019 Release */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar3;
  
  if (DAT_18001ef61 == '\0') {
    if (1 < param_1) {
      FUN_18000d280(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_18001ef68 = _DAT_1800169d0;
      uRam000000018001ef70 = _UNK_1800169d8;
      _DAT_18001ef78 = 0xffffffffffffffff;
      _DAT_18001ef80 = _DAT_1800169d0;
      uRam000000018001ef88 = _UNK_1800169d8;
      _DAT_18001ef90 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_18001ef68);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_18001ef80), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_18001ef61 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}


/* Function 18000cbec __scrt_is_nonwritable_in_current_image */

/* Library Function - Single Match
    __scrt_is_nonwritable_in_current_image
   
   Library: Visual Studio 2019 Release */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar1 = 0x5a4d;
  if (((IMAGE_DOS_HEADER_180000000.e_magic == (char  [2])0x5a4d) &&
      (lVar3 = (longlong)(int)IMAGE_DOS_HEADER_180000000.e_lfanew,
      *(int *)(lVar3 + 0x180000000) == 0x4550)) &&
     (uVar1 = 0x20b, *(short *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -4) == 0x20b
     )) {
    lVar4 = lVar3 + 0x180000018 +
            (ulonglong)*(ushort *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -8);
    uVar1 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_180000000.e_magic + lVar3 + 6);
    lVar3 = lVar4 + uVar1 * 0x28;
    for (; lVar4 != lVar3; lVar4 = lVar4 + 0x28) {
      if (((ulonglong)*(uint *)(lVar4 + 0xc) <= param_1 - 0x180000000U) &&
         (uVar1 = (ulonglong)(*(int *)(lVar4 + 8) + *(uint *)(lVar4 + 0xc)),
         param_1 - 0x180000000U < uVar1)) goto LAB_18000cc62;
    }
    lVar4 = 0;
LAB_18000cc62:
    if (lVar4 == 0) {
      uVar1 = uVar1 & 0xffffffffffffff00;
    }
    else {
      uVar2 = (uint7)(uVar1 >> 8);
      if (*(int *)(lVar4 + 0x24) < 0) {
        uVar1 = (ulonglong)uVar2 << 8;
      }
      else {
        uVar1 = CONCAT71(uVar2,1);
      }
    }
  }
  else {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}


/* Function 18000cc84 __scrt_release_startup_lock */

/* Library Function - Single Match
    __scrt_release_startup_lock
   
   Library: Visual Studio 2019 Release */

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_18001ef58 = 0;
    UNLOCK();
  }
  return;
}


/* Function 18000cca8 __scrt_uninitialize_crt */

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_18001ef60 == '\0') || (param_2 == '\0')) {
    FUN_1800099bc();
    FUN_1800099bc();
  }
  return 1;
}


/* Function 18000ccd4 _onexit */

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_18001ef68 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_18001ef68);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}


/* Function 18000cd10 atexit */

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}


/* Function 18000cd30 FUN_18000cd30 */

ulonglong FUN_18000cd30(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  
  if (param_2 == 0) {
    iVar2 = dllmain_crt_process_detach(param_3 != 0);
    return CONCAT44(extraout_var,iVar2);
  }
  if (param_2 != 1) {
    if (param_2 == 2) {
      bVar1 = FUN_18000ca30();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      bVar1 = FUN_18000ca58();
    }
    return (ulonglong)bVar1;
  }
  uVar3 = FUN_18000cd80(param_1,param_3);
  return uVar3;
}


/* Function 18000cd80 FUN_18000cd80 */

undefined8 FUN_18000cd80(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  
  uVar5 = __scrt_initialize_crt(0);
  if ((char)uVar5 != '\0') {
    uVar5 = __scrt_acquire_startup_lock();
    bVar2 = true;
    if (DAT_18001ef50 != 0) {
      FUN_18000d280(7);
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    DAT_18001ef50 = 1;
    bVar3 = __scrt_dllmain_before_initialize_c();
    if (bVar3) {
      FUN_18000d358();
      FUN_18000d384();
      iVar4 = _initterm_e(&DAT_1800165f8,&DAT_180016608);
      if ((iVar4 == 0) && (uVar6 = __scrt_dllmain_after_initialize_c(), (char)uVar6 != '\0')) {
        _initterm(&DAT_1800165c0,&DAT_1800165f0);
        DAT_18001ef50 = 2;
        bVar2 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar5);
    if (!bVar2) {
      plVar7 = (longlong *)FUN_18000d3a0();
      if ((*plVar7 != 0) &&
         (uVar8 = __scrt_is_nonwritable_in_current_image((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,2,param_2);
      }
      DAT_18001ef98 = DAT_18001ef98 + 1;
      return 1;
    }
  }
  return 0;
}


/* Function 18000ce94 dllmain_crt_process_detach */

/* Library Function - Single Match
    int __cdecl dllmain_crt_process_detach(bool)
   
   Library: Visual Studio 2019 Release */

int __cdecl dllmain_crt_process_detach(bool param_1)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined7 in_register_00000009;
  
  if (DAT_18001ef98 < 1) {
    uVar3 = 0;
  }
  else {
    DAT_18001ef98 = DAT_18001ef98 + -1;
    uVar5 = __scrt_acquire_startup_lock();
    if (DAT_18001ef50 != 2) {
      FUN_18000d280(7);
      pcVar1 = (code *)swi(3);
      iVar4 = (*pcVar1)();
      return iVar4;
    }
    __scrt_dllmain_uninitialize_c();
    FUN_18000d368();
    DAT_18001ef50 = 0;
    __scrt_release_startup_lock((char)uVar5);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(in_register_00000009,param_1),'\0');
    uVar3 = -(uint)(cVar2 != '\0') & 1;
    __scrt_dllmain_uninitialize_critical();
  }
  return uVar3;
}


/* Function 18000cf14 dllmain_dispatch */

/* Library Function - Single Match
    int __cdecl dllmain_dispatch(struct HINSTANCE__ * __ptr64 const,unsigned long,void * __ptr64
   const)
   
   Library: Visual Studio 2019 Release */

int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int iVar3;
  
  if ((param_2 == 0) && (DAT_18001ef98 < 1)) {
    return 0;
  }
  if (param_2 - 1 < 2) {
    if ((DAT_1800169e0 != 0) &&
       (iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(), iVar3 == 0)) {
      return 0;
    }
    uVar1 = FUN_18000cd30(param_1,param_2,(longlong)param_3);
    if ((int)uVar1 == 0) {
      return 0;
    }
  }
  uVar2 = DllMain(param_1,param_2);
  iVar3 = (int)uVar2;
  if ((param_2 == 1) && (iVar3 == 0)) {
    DllMain(param_1,0);
    dllmain_crt_process_detach(param_3 != (void *)0x0);
    if (DAT_1800169e0 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,0,param_3);
    }
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    uVar1 = FUN_18000cd30(param_1,param_2,(longlong)param_3);
    iVar3 = (int)uVar1;
    if (iVar3 != 0) {
      if (DAT_1800169e0 == 0) {
        iVar3 = 1;
      }
      else {
        iVar3 = (*(code *)PTR__guard_dispatch_icall_1800165a8)(param_1,param_2,param_3);
      }
    }
  }
  return iVar3;
}


/* Function 18000d050 entry */

void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}


/* Function 18000d090 FUN_18000d090 */

void FUN_18000d090(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  return;
}


/* Function 18000d0a0 free */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d42c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}


/* Function 18000d0a8 FUN_18000d0a8 */

void FUN_18000d0a8(void)

{
  undefined8 local_28 [5];
  
  FUN_18000504c(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_18001a990);
}


/* Function 18000d0c8 __isa_available_init */

/* WARNING: Removing unreachable block (ram,0x00018000d187) */
/* WARNING: Removing unreachable block (ram,0x00018000d102) */
/* WARNING: Removing unreachable block (ram,0x00018000d0db) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __isa_available_init
   
   Library: Visual Studio 2019 Release */

undefined8 __isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar6 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[1] == 0x756e6547 && piVar1[3] == 0x6c65746e) && piVar1[2] == 0x49656e69) {
    _DAT_18001e110 = 0xffffffffffffffff;
    uVar5 = *puVar2 & 0xfff3ff0;
    if ((((uVar5 == 0x106c0) || (uVar5 == 0x20660)) || (uVar5 == 0x20670)) ||
       ((uVar5 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar5 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_18001f524 = DAT_18001f524 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar6 >> 9 & 1) != 0) {
      DAT_18001f524 = DAT_18001f524 | 2;
    }
  }
  _DAT_18001e108 = 1;
  DAT_18001e10c = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_18001e108 = 2;
    DAT_18001e10c = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) && ((in_XCR0 & 6) == 6)) {
      DAT_18001e10c = 0xe;
      _DAT_18001e108 = 3;
      if ((uVar6 & 0x20) != 0) {
        _DAT_18001e108 = 5;
        DAT_18001e10c = 0x2e;
        if (((uVar6 & 0xd0030000) == 0xd0030000) && ((in_XCR0 & 0xe0) == 0xe0)) {
          DAT_18001e10c = 0x6e;
          _DAT_18001e108 = 6;
        }
      }
    }
  }
  return 0;
}


/* Function 18000d26c FUN_18000d26c */

undefined8 FUN_18000d26c(void)

{
  return 1;
}


/* Function 18000d274 __scrt_is_ucrt_dll_in_use */

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Library: Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_18001e120 != 0;
}


/* Function 18000d280 FUN_18000d280 */

void FUN_18000d280(undefined4 param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(param_1);
  return;
}


/* Function 18000d288 __security_init_cookie */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  _FILETIME local_res10;
  LARGE_INTEGER local_res18;
  
  if (DAT_18001e100 == 0x2b992ddfa232) {
    local_res10.dwLowDateTime = 0;
    local_res10.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res10);
    local_res8 = local_res10;
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res18);
    DAT_18001e100 =
         ((ulonglong)local_res18.s.LowPart << 0x20 ^
          CONCAT44(local_res18.s.HighPart,local_res18.s.LowPart) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
    if (DAT_18001e100 == 0x2b992ddfa232) {
      DAT_18001e100 = 0x2b992ddfa233;
    }
  }
  _DAT_18001e0f8 = ~DAT_18001e100;
  return;
}


/* Function 18000d334 DllMain */

/* Library Function - Single Match
    DllMain
   
   Library: Visual Studio 2019 Release */

undefined8 DllMain(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_1800169e0 == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}


/* Function 18000d358 FUN_18000d358 */

void FUN_18000d358(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d35f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_18001f530);
  return;
}


/* Function 18000d368 FUN_18000d368 */

void FUN_18000d368(void)

{
  __std_type_info_destroy_list(&DAT_18001f530);
  return;
}


/* Function 18000d374 FUN_18000d374 */

undefined * FUN_18000d374(void)

{
  return &DAT_18001f540;
}


/* Function 18000d37c FUN_18000d37c */

undefined * FUN_18000d37c(void)

{
  return &DAT_18001f548;
}


/* Function 18000d384 FUN_18000d384 */

void FUN_18000d384(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_18000d374();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_18000d37c();
  *puVar1 = *puVar1 | 2;
  return;
}


/* Function 18000d3a0 FUN_18000d3a0 */

undefined * FUN_18000d3a0(void)

{
  return &DAT_18001f678;
}


/* Function 18000d3b0 __CxxFrameHandler4 */

void __CxxFrameHandler4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler4();
  return;
}


/* Function 18000d3c0 _purecall */

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}


/* Function 18000d3c6 memset */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d3c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}


/* Function 18000d3d2 _CxxThrowException */

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3d2. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}


/* Function 18000d3d8 __std_type_info_destroy_list */

void __std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_type_info_destroy_list();
  return;
}


/* Function 18000d3de wcslen */

size_t __cdecl wcslen(wchar_t *_Str)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d3de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = wcslen(_Str);
  return sVar1;
}


/* Function 18000d3e4 _callnewh */

int __cdecl _callnewh(size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d3e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _callnewh(_Size);
  return iVar1;
}


/* Function 18000d3ea malloc */

void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d3ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = malloc(_Size);
  return pvVar1;
}


/* Function 18000d3f0 _seh_filter_dll */

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _seh_filter_dll();
  return;
}


/* Function 18000d3f6 _configure_narrow_argv */

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _configure_narrow_argv();
  return;
}


/* Function 18000d3fc _initialize_narrow_environment */

void _initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d3fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_narrow_environment();
  return;
}


/* Function 18000d402 _initialize_onexit_table */

void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d402. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initialize_onexit_table();
  return;
}


/* Function 18000d408 _register_onexit_function */

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d408. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_onexit_function();
  return;
}


/* Function 18000d40e _execute_onexit_table */

void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d40e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _execute_onexit_table();
  return;
}


/* Function 18000d414 _crt_atexit */

void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d414. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _crt_atexit();
  return;
}


/* Function 18000d41a _cexit */

void __cdecl _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d41a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}


/* Function 18000d420 _initterm */

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}


/* Function 18000d426 _initterm_e */

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d426. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}


/* Function 18000d42c free */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d42c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}


/* Function 18000d432 WindowsCreateString */

void WindowsCreateString(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d432. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsCreateString();
  return;
}


/* Function 18000d438 WindowsDeleteString */

void WindowsDeleteString(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d438. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsDeleteString();
  return;
}


/* Function 18000d43e WindowsCreateStringReference */

void WindowsCreateStringReference(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d43e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsCreateStringReference();
  return;
}


/* Function 18000d444 CoCreateFreeThreadedMarshaler */

HRESULT __stdcall CoCreateFreeThreadedMarshaler(LPUNKNOWN punkOuter,LPUNKNOWN *ppunkMarshal)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d444. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = CoCreateFreeThreadedMarshaler(punkOuter,ppunkMarshal);
  return HVar1;
}


/* Function 18000d44a WindowsDuplicateString */

void WindowsDuplicateString(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d44a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsDuplicateString();
  return;
}


/* Function 18000d450 WindowsGetStringRawBuffer */

void WindowsGetStringRawBuffer(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsGetStringRawBuffer();
  return;
}


/* Function 18000d456 WindowsCompareStringOrdinal */

void WindowsCompareStringOrdinal(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d456. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsCompareStringOrdinal();
  return;
}


/* Function 18000d45c WindowsIsStringEmpty */

void WindowsIsStringEmpty(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d45c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WindowsIsStringEmpty();
  return;
}


/* Function 18000d470 DllCanUnloadNow */

HRESULT __stdcall DllCanUnloadNow(void)

{
  bool bVar1;
  
                    /* 0xd470  1  DllCanUnloadNow */
  bVar1 = Platform::Details::TerminateModule(DAT_18001ef08);
  return (HRESULT)!bVar1;
}


/* Function 18000d490 DllGetActivationFactory */

void DllGetActivationFactory(HSTRING__ *param_1,IActivationFactory **param_2)

{
                    /* 0xd490  2  DllGetActivationFactory */
                    /* WARNING: Could not recover jumptable at 0x00018000d4a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Platform::Details::GetActivationFactory(DAT_18001ef08,param_1,param_2);
  return;
}


/* Function 18000d4a8 TerminateModule */

bool __cdecl Platform::Details::TerminateModule(ModuleBase *param_1)

{
  bool bVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d4a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = TerminateModule(param_1);
  return bVar1;
}


/* Function 18000d4ae SysFreeString */

void __stdcall SysFreeString(BSTR bstrString)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d4ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SysFreeString(bstrString);
  return;
}


/* Function 18000d4b4 GetRestrictedErrorInfo */

void GetRestrictedErrorInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d4b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetRestrictedErrorInfo();
  return;
}


/* Function 18000d4ba RoOriginateLanguageException */

void RoOriginateLanguageException(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d4ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RoOriginateLanguageException();
  return;
}


/* Function 18000d4c0 InterlockedPushEntrySList */

PSLIST_ENTRY_conflict __stdcall
InterlockedPushEntrySList(PSLIST_HEADER ListHead,PSLIST_ENTRY ListEntry)

{
  PSLIST_ENTRY_conflict p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = InterlockedPushEntrySList(ListHead,ListEntry);
  return p_Var1;
}


/* Function 18000d4c6 RoGetActivationFactory */

void RoGetActivationFactory(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d4c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RoGetActivationFactory();
  return;
}


/* Function 18000d4cc CoIncrementMTAUsage */

void CoIncrementMTAUsage(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000d4cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoIncrementMTAUsage();
  return;
}


/* Function 18000d4d2 FormatMessageW */

DWORD __stdcall
FormatMessageW(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPWSTR lpBuffer,
              DWORD nSize,va_list *Arguments)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d4d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = FormatMessageW(dwFlags,lpSource,dwMessageId,dwLanguageId,lpBuffer,nSize,Arguments);
  return DVar1;
}


/* Function 18000d4d8 GetProcessHeap */

HANDLE __stdcall GetProcessHeap(void)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d4d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetProcessHeap();
  return pvVar1;
}


/* Function 18000d4de HeapFree */

BOOL __stdcall HeapFree(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d4de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = HeapFree(hHeap,dwFlags,lpMem);
  return BVar1;
}


/* Function 18000d4e4 SysStringLen */

UINT __stdcall SysStringLen(BSTR param_1)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000d4e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = SysStringLen(param_1);
  return UVar1;
}


/* Function 18000d4ec FUN_18000d4ec */

void FUN_18000d4ec(int *param_1,undefined8 *param_2,longlong *param_3,longlong *param_4,
                  longlong *param_5,longlong *param_6)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 local_30 [5];
  
  FUN_1800077e0((undefined8 *)((longlong)param_2 + 0xa61),param_6,param_4,param_5);
  *param_2 = FUN_18000d6a0;
  *(uint *)(param_2 + 1) = (~-(uint)(*param_1 != 0) & 0x10000) + 2;
  puVar3 = param_2 + -2;
  for (lVar2 = 0x10; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined8 *)((longlong)puVar3 + 1);
  }
  FUN_180007af8(param_2 + -2,param_6,param_4,param_5);
  FUN_180009aa4(param_3);
  FUN_180007868(param_2 + -2,param_3,param_4,param_5);
  FUN_180008084(param_2 + -2,(undefined1 *)(param_2 + 0x14c));
  cVar1 = FUN_1800099bc();
  if (cVar1 == '\0') {
    FUN_180007b90(local_30,param_2);
    _guard_check_icall();
  }
  else {
    FUN_18000d6a0((longlong)param_2);
  }
  return;
}


/* Function 18000d6a0 FUN_18000d6a0 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x000180012892) */

void FUN_18000d6a0(longlong param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  bool bVar3;
  char cVar4;
  undefined8 uVar5;
  longlong *plVar6;
  void *pvVar7;
  undefined8 *puVar8;
  longlong *in_RDX;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined1 auStackY_1d88 [32];
  undefined8 auStack_1538 [2];
  undefined8 *puStack_1528;
  undefined8 *puStack_1520;
  undefined8 uStack_1518;
  undefined8 *puStack_1510;
  undefined8 uStack_1508;
  undefined8 *puStack_1500;
  undefined8 uStack_14f8;
  longlong lStack_14f0;
  undefined8 *puStack_14e8;
  undefined8 uStack_14e0;
  undefined8 *puStack_14d8;
  undefined8 uStack_14d0;
  undefined8 *puStack_14c8;
  undefined8 uStack_14c0;
  undefined8 *puStack_14b8;
  undefined8 uStack_14b0;
  undefined8 *puStack_14a8;
  undefined8 uStack_14a0;
  undefined8 *puStack_1498;
  undefined8 uStack_1490;
  undefined8 *puStack_1488;
  undefined8 *puStack_1480;
  undefined8 uStack_1478;
  undefined8 *puStack_1470;
  undefined8 uStack_1468;
  undefined8 *puStack_1460;
  undefined8 uStack_1458;
  longlong *plStack_1450;
  undefined8 *puStack_1448;
  undefined8 uStack_1440;
  undefined8 *puStack_1438;
  undefined8 uStack_1430;
  undefined8 *puStack_1428;
  undefined8 uStack_1420;
  undefined8 *puStack_1418;
  undefined8 *puStack_1410;
  undefined8 *puStack_1408;
  undefined8 *puStack_1400;
  undefined1 *puStack_13f8;
  char *pcStack_13f0;
  longlong lStack_13e8;
  longlong lStack_13e0;
  char *pcStack_13d8;
  undefined8 *puStack_13d0;
  void *pvStack_13c8;
  undefined8 *puStack_13c0;
  undefined8 uStack_13b8;
  undefined8 *puStack_13b0;
  undefined8 uStack_13a8;
  undefined8 *puStack_13a0;
  Exception *pEStack_1398;
  undefined8 *puStack_1390;
  undefined8 uStack_1388;
  undefined8 *puStack_1380;
  undefined8 uStack_1378;
  undefined8 *puStack_1370;
  undefined8 uStack_1368;
  undefined8 *puStack_1360;
  longlong *plStack_1358;
  undefined8 *puStack_1350;
  longlong *plStack_1348;
  undefined8 *puStack_1340;
  undefined8 uStack_1338;
  undefined8 auStack_1330 [2];
  undefined8 *puStack_1320;
  undefined8 *puStack_1318;
  undefined8 uStack_1310;
  undefined8 *puStack_1308;
  undefined8 uStack_1300;
  undefined8 *puStack_12f8;
  undefined8 uStack_12f0;
  longlong lStack_12e8;
  undefined8 *puStack_12e0;
  undefined8 uStack_12d8;
  undefined8 *puStack_12d0;
  undefined8 uStack_12c8;
  undefined8 *puStack_12c0;
  undefined8 uStack_12b8;
  undefined8 *puStack_12b0;
  undefined8 uStack_12a8;
  undefined8 *puStack_12a0;
  undefined8 uStack_1298;
  undefined8 *puStack_1290;
  undefined8 uStack_1288;
  undefined8 *puStack_1280;
  undefined8 *puStack_1278;
  undefined8 uStack_1270;
  undefined8 *puStack_1268;
  undefined8 uStack_1260;
  undefined8 *puStack_1258;
  undefined8 uStack_1250;
  longlong *plStack_1248;
  undefined8 *puStack_1240;
  undefined8 uStack_1238;
  undefined8 *puStack_1230;
  undefined8 uStack_1228;
  undefined8 *puStack_1220;
  undefined8 uStack_1218;
  undefined8 *puStack_1210;
  undefined8 *puStack_1208;
  undefined8 *puStack_1200;
  undefined8 *puStack_11f8;
  undefined1 *puStack_11f0;
  char *pcStack_11e8;
  longlong lStack_11e0;
  longlong lStack_11d8;
  char *pcStack_11d0;
  undefined8 *puStack_11c8;
  void *pvStack_11c0;
  undefined8 *puStack_11b8;
  undefined8 uStack_11b0;
  undefined8 *puStack_11a8;
  undefined8 uStack_11a0;
  undefined8 *puStack_1198;
  Exception *pEStack_1190;
  undefined8 *puStack_1188;
  undefined8 uStack_1180;
  undefined8 *puStack_1178;
  undefined8 uStack_1170;
  undefined8 *puStack_1168;
  undefined8 uStack_1160;
  undefined8 *puStack_1158;
  longlong *plStack_1150;
  undefined8 *puStack_1148;
  longlong *plStack_1140;
  undefined8 *puStack_1138;
  undefined8 uStack_1130;
  undefined8 auStack_1128 [2];
  undefined8 *puStack_1118;
  undefined8 *puStack_1110;
  undefined8 uStack_1108;
  undefined8 *puStack_1100;
  undefined8 uStack_10f8;
  undefined8 *puStack_10f0;
  undefined8 uStack_10e8;
  longlong lStack_10e0;
  undefined8 *puStack_10d8;
  undefined8 uStack_10d0;
  undefined8 *puStack_10c8;
  undefined8 uStack_10c0;
  undefined8 *puStack_10b8;
  undefined8 uStack_10b0;
  undefined8 *puStack_10a8;
  undefined8 uStack_10a0;
  undefined8 *puStack_1098;
  undefined8 uStack_1090;
  undefined8 *puStack_1088;
  undefined8 uStack_1080;
  undefined8 *puStack_1078;
  undefined8 *puStack_1070;
  undefined8 uStack_1068;
  undefined8 *puStack_1060;
  undefined8 uStack_1058;
  undefined8 *puStack_1050;
  undefined8 uStack_1048;
  longlong *plStack_1040;
  undefined8 *puStack_1038;
  undefined8 uStack_1030;
  undefined8 *puStack_1028;
  undefined8 uStack_1020;
  undefined8 *puStack_1018;
  undefined8 uStack_1010;
  undefined8 *puStack_1008;
  undefined8 *puStack_1000;
  undefined8 *puStack_ff8;
  undefined8 *puStack_ff0;
  undefined1 *puStack_fe8;
  char *pcStack_fe0;
  longlong lStack_fd8;
  longlong lStack_fd0;
  char *pcStack_fc8;
  undefined8 *puStack_fc0;
  void *pvStack_fb8;
  undefined8 *puStack_fb0;
  undefined8 uStack_fa8;
  undefined8 *puStack_fa0;
  undefined8 uStack_f98;
  undefined8 *puStack_f90;
  Exception *pEStack_f88;
  undefined8 *puStack_f80;
  undefined8 uStack_f78;
  undefined8 *puStack_f70;
  undefined8 uStack_f68;
  undefined8 *puStack_f60;
  undefined8 uStack_f58;
  undefined8 *puStack_f50;
  longlong *plStack_f48;
  undefined8 *puStack_f40;
  longlong *plStack_f38;
  undefined8 *puStack_f30;
  undefined8 uStack_f28;
  undefined8 auStack_f20 [2];
  undefined8 *puStack_f10;
  undefined8 *puStack_f08;
  undefined8 uStack_f00;
  undefined8 *puStack_ef8;
  undefined8 uStack_ef0;
  undefined8 *puStack_ee8;
  undefined8 uStack_ee0;
  longlong lStack_ed8;
  undefined8 *puStack_ed0;
  undefined8 uStack_ec8;
  undefined8 *puStack_ec0;
  undefined8 uStack_eb8;
  undefined8 *puStack_eb0;
  undefined8 uStack_ea8;
  undefined8 *puStack_ea0;
  undefined8 uStack_e98;
  undefined8 *puStack_e90;
  undefined8 uStack_e88;
  undefined8 *puStack_e80;
  undefined8 uStack_e78;
  undefined8 *puStack_e70;
  undefined8 *puStack_e68;
  undefined8 uStack_e60;
  undefined8 *puStack_e58;
  undefined8 uStack_e50;
  undefined8 *puStack_e48;
  undefined8 uStack_e40;
  longlong *plStack_e38;
  undefined8 *puStack_e30;
  undefined8 uStack_e28;
  undefined8 *puStack_e20;
  undefined8 uStack_e18;
  undefined8 *puStack_e10;
  undefined8 uStack_e08;
  undefined8 *puStack_e00;
  undefined8 *puStack_df8;
  undefined8 *puStack_df0;
  undefined8 *puStack_de8;
  undefined1 *puStack_de0;
  char *pcStack_dd8;
  longlong lStack_dd0;
  longlong lStack_dc8;
  char *pcStack_dc0;
  undefined8 *puStack_db8;
  void *pvStack_db0;
  undefined8 *puStack_da8;
  undefined8 uStack_da0;
  undefined8 *puStack_d98;
  undefined8 uStack_d90;
  undefined8 *puStack_d88;
  Exception *pEStack_d80;
  undefined8 *puStack_d78;
  undefined8 uStack_d70;
  undefined8 *puStack_d68;
  undefined8 uStack_d60;
  undefined8 *puStack_d58;
  undefined8 uStack_d50;
  undefined8 *puStack_d48;
  longlong *plStack_d40;
  undefined8 *puStack_d38;
  longlong *plStack_d30;
  undefined8 *puStack_d28;
  undefined8 uStack_d20;
  undefined8 auStack_d18 [2];
  undefined8 *puStack_d08;
  undefined8 uStack_d00;
  undefined8 *puStack_cf8;
  undefined8 *puStack_cf0;
  undefined8 uStack_ce8;
  undefined8 *puStack_ce0;
  undefined8 uStack_cd8;
  undefined8 *puStack_cd0;
  undefined8 uStack_cc8;
  longlong lStack_cc0;
  undefined8 *puStack_cb8;
  undefined8 uStack_cb0;
  undefined8 *puStack_ca8;
  undefined8 uStack_ca0;
  undefined8 *puStack_c98;
  undefined8 uStack_c90;
  undefined1 *puStack_c88;
  undefined1 *puStack_c80;
  undefined1 *puStack_c78;
  undefined8 *puStack_c70;
  char *pcStack_c68;
  undefined8 *puStack_c60;
  undefined8 *puStack_c58;
  undefined8 uStack_c50;
  undefined8 *puStack_c48;
  undefined8 uStack_c40;
  undefined8 *puStack_c38;
  undefined8 uStack_c30;
  longlong lStack_c28;
  undefined8 *puStack_c20;
  undefined8 uStack_c18;
  undefined8 *puStack_c10;
  undefined8 uStack_c08;
  undefined8 *puStack_c00;
  undefined8 uStack_bf8;
  undefined8 *puStack_bf0;
  undefined8 uStack_be8;
  undefined8 *puStack_be0;
  undefined8 uStack_bd8;
  undefined8 *puStack_bd0;
  undefined8 uStack_bc8;
  undefined8 *puStack_bc0;
  undefined8 *puStack_bb8;
  undefined8 uStack_bb0;
  undefined8 *puStack_ba8;
  undefined8 uStack_ba0;
  undefined8 *puStack_b98;
  undefined8 uStack_b90;
  longlong *plStack_b88;
  longlong *plStack_b80;
  undefined8 *puStack_b78;
  undefined8 *puStack_b70;
  undefined8 *puStack_b68;
  undefined8 *puStack_b60;
  undefined8 *puStack_b58;
  size_t *psStack_b50;
  undefined8 *puStack_b48;
  undefined8 *puStack_b40;
  undefined8 *puStack_b38;
  undefined8 *puStack_b30;
  undefined8 uStack_b28;
  undefined8 *puStack_b20;
  undefined8 uStack_b18;
  undefined8 *puStack_b10;
  undefined8 uStack_b08;
  void *pvStack_b00;
  undefined8 *puStack_af8;
  void *pvStack_af0;
  longlong *plStack_ae8;
  longlong lStack_ae0;
  longlong lStack_ad8;
  undefined8 *puStack_ad0;
  undefined8 uStack_ac8;
  undefined8 *puStack_ac0;
  String *pSStack_ab8;
  undefined8 *puStack_ab0;
  undefined8 uStack_aa8;
  undefined8 *puStack_aa0;
  undefined8 uStack_a98;
  undefined8 *puStack_a90;
  undefined8 uStack_a88;
  undefined8 *puStack_a80;
  undefined8 *puStack_a78;
  undefined8 uStack_a70;
  longlong lStack_a68;
  undefined8 *puStack_a60;
  undefined8 uStack_a58;
  undefined8 *puStack_a50;
  undefined8 uStack_a48;
  undefined8 *puStack_a40;
  undefined8 *puStack_a38;
  undefined8 uStack_a30;
  undefined8 uStack_a28;
  undefined8 *puStack_a20;
  longlong lStack_a18;
  undefined8 *puStack_a10;
  undefined8 *puStack_a08;
  undefined8 *puStack_a00;
  undefined8 *puStack_9f8;
  undefined8 *puStack_9f0;
  undefined8 *puStack_9e8;
  undefined8 *puStack_6f8;
  undefined8 uStack_6f0;
  undefined8 *puStack_6e8;
  undefined8 uStack_6e0;
  undefined8 *puStack_6d8;
  undefined8 uStack_6d0;
  undefined8 *puStack_6c8;
  undefined8 *puStack_6c0;
  undefined8 *puStack_6b8;
  undefined8 uStack_6b0;
  undefined8 *puStack_6a8;
  undefined8 uStack_6a0;
  undefined8 *puStack_698;
  undefined8 uStack_690;
  undefined8 *puStack_688;
  undefined8 *puStack_680;
  undefined8 *puStack_678;
  undefined8 *puStack_670;
  undefined8 *puStack_668;
  undefined8 uStack_660;
  undefined8 uStack_658;
  undefined8 *puStack_650;
  undefined8 uStack_648;
  undefined8 *puStack_640;
  undefined1 *puStack_638;
  char *pcStack_630;
  undefined4 *puStack_628;
  undefined8 *puStack_620;
  undefined8 uStack_618;
  undefined8 *puStack_610;
  undefined8 uStack_608;
  undefined2 *puStack_600;
  undefined8 *puStack_5f8;
  undefined8 *puStack_5f0;
  undefined8 uStack_5e8;
  longlong *plStack_5e0;
  undefined8 *puStack_5d8;
  undefined8 *puStack_5d0;
  longlong lStack_5c8;
  longlong lStack_5c0;
  longlong lStack_5b8;
  longlong lStack_5b0;
  longlong lStack_5a8;
  longlong lStack_5a0;
  undefined8 *puStack_598;
  undefined8 *puStack_590;
  longlong *plStack_588;
  undefined8 *puStack_580;
  wchar_t *pwStack_578;
  undefined4 *puStack_570;
  undefined8 *puStack_568;
  longlong *plStack_560;
  undefined8 *puStack_558;
  undefined8 *puStack_550;
  longlong lStack_4a8;
  longlong lStack_4a0;
  longlong lStack_498;
  longlong lStack_490;
  longlong lStack_488;
  longlong lStack_480;
  undefined8 *puStack_478;
  undefined8 *puStack_470;
  longlong *plStack_468;
  undefined8 *puStack_460;
  wchar_t *pwStack_458;
  undefined1 *puStack_448;
  longlong lStack_440;
  undefined8 *puStack_438;
  undefined1 *puStack_430;
  longlong lStack_428;
  undefined4 *puStack_420;
  undefined8 *puStack_418;
  undefined8 uStack_410;
  undefined8 *puStack_408;
  undefined8 uStack_400;
  undefined2 *puStack_3f8;
  undefined8 *puStack_3f0;
  longlong lStack_3e8;
  undefined8 uStack_3e0;
  longlong lStack_3d0;
  undefined8 *puStack_3c8;
  undefined8 uStack_3c0;
  longlong *plStack_3a8;
  longlong lStack_3a0;
  longlong lStack_398;
  undefined8 *puStack_390;
  wchar_t *pwStack_388;
  undefined8 *puStack_380;
  void *pvStack_378;
  void *pvStack_370;
  void *pvStack_368;
  void *pvStack_360;
  void *pvStack_358;
  void *pvStack_350;
  size_t sStack_330;
  longlong *plStack_328;
  ulonglong local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x18000d6af;
  local_10 = DAT_18001e100 ^ (ulonglong)auStackY_1d88;
  switch(*(undefined2 *)(param_1 + 8)) {
  default:
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  case 1:
    break;
  case 2:
    _guard_check_icall();
    *(undefined4 *)(param_1 + 0x3c8) = 0;
    pwStack_388 = FUN_1800011a0((wchar_t *)(param_1 + 0x10),
                                L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync"
                                ,0x180017090,0x83);
    uVar5 = FUN_1800082cc(*(longlong **)(param_1 + 0xa71));
    *(undefined8 *)(param_1 + 0x440) = uVar5;
    *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_1 + 0x440);
    plVar6 = FUN_180001c50(*(longlong **)(param_1 + 0x68));
    *(longlong **)(param_1 + 0x460) = plVar6;
    *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(param_1 + 0x460);
    FUN_180001c34(*(longlong **)(param_1 + 0x68));
    plVar6 = FUN_180006658((longlong *)(param_1 + 0xb0),(longlong *)(param_1 + 0x60));
    *(longlong **)(param_1 + 0x450) = plVar6;
    puStack_380 = FUN_180008874((undefined8 *)(param_1 + 0x70),*(longlong **)(param_1 + 0x450));
    FUN_180007a08((longlong *)(param_1 + 0xb0));
    uVar5 = FUN_18000176c(*(longlong **)(param_1 + 0xa71));
    *(undefined8 *)(param_1 + 0x470) = uVar5;
    *(undefined8 *)(param_1 + 200) = *(undefined8 *)(param_1 + 0x470);
    uVar5 = FUN_18000176c(*(longlong **)(param_1 + 200));
    *(undefined8 *)(param_1 + 0x480) = uVar5;
    *(undefined8 *)(param_1 + 0xc0) = *(undefined8 *)(param_1 + 0x480);
    plVar6 = FUN_180001c50(*(longlong **)(param_1 + 0xc0));
    *(longlong **)(param_1 + 0x4c0) = plVar6;
    *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0x4c0);
    FUN_180001c34(*(longlong **)(param_1 + 0xc0));
    FUN_180001c34(*(longlong **)(param_1 + 200));
    uVar5 = FUN_180001a40();
    *(undefined8 *)(param_1 + 0x4b0) = uVar5;
    *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_1 + 0x4b0);
    uVar5 = FUN_180007584();
    *(undefined8 *)(param_1 + 0x4a0) = uVar5;
    *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(param_1 + 0x4a0);
    plVar6 = FUN_180001c50(*(longlong **)(param_1 + 0xe0));
    *(longlong **)(param_1 + 0x490) = plVar6;
    *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(param_1 + 0x490);
    FUN_180001c34(*(longlong **)(param_1 + 0xe0));
    func_0x000180007a28(param_1 + 0xe8,0x20);
    pvStack_378 = FUN_180001a50((void *)(param_1 + 0xe8),L"Result");
    func_0x000180007a28(param_1 + 0x108,0x20);
    pvStack_370 = FUN_180001a50((void *)(param_1 + 0x108),L"ImageFileName");
    func_0x000180007a28(param_1 + 0x128,0x20);
    pvStack_368 = FUN_180001a50((void *)(param_1 + 0x128),L"ImageFileSharedToken");
    func_0x000180007a28(param_1 + 0x148,0x20);
    pvStack_360 = FUN_180001a50((void *)(param_1 + 0x148),L"MetadataFileSharedToken");
    func_0x000180007a28(param_1 + 0x168,0x20);
    pvStack_358 = FUN_180001a50((void *)(param_1 + 0x168),L"FirstLineText");
    func_0x000180007a28(param_1 + 0x188,0x20);
    pvStack_350 = FUN_180001a50((void *)(param_1 + 0x188),L"SecondLineText");
    uVar5 = FUN_180001bb4('\0',*(undefined8 **)(param_1 + 0xb8),&DAT_180016ae8);
    *(undefined8 *)(param_1 + 0x4d0) = uVar5;
    *(undefined8 *)(param_1 + 0x1b0) = *(undefined8 *)(param_1 + 0x4d0);
    *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) | 1;
    uVar5 = FUN_180001ac0(param_1 + 0x108);
    *(undefined8 *)(param_1 + 0x530) = uVar5;
    uVar2 = FUN_1800016dc(*(longlong **)(param_1 + 0x1b0),*(undefined8 *)(param_1 + 0x530));
    *(undefined1 *)(param_1 + 0x520) = uVar2;
    if (*(char *)(param_1 + 0x520) == '\0') {
code_r0x00018000ea82:
      *(undefined4 *)(param_1 + 0x200) = 1;
    }
    else {
      uVar5 = FUN_180001bb4('\0',*(undefined8 **)(param_1 + 0xb8),&DAT_180016ae8);
      *(undefined8 *)(param_1 + 0x510) = uVar5;
      *(undefined8 *)(param_1 + 0x1b8) = *(undefined8 *)(param_1 + 0x510);
      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) | 2;
      uVar5 = FUN_180001ac0(param_1 + 0x128);
      *(undefined8 *)(param_1 + 0x4e0) = uVar5;
      uVar2 = FUN_1800016dc(*(longlong **)(param_1 + 0x1b8),*(undefined8 *)(param_1 + 0x4e0));
      *(undefined1 *)(param_1 + 0x500) = uVar2;
      if (*(char *)(param_1 + 0x500) == '\0') goto code_r0x00018000ea82;
      uVar5 = FUN_180001bb4('\0',*(undefined8 **)(param_1 + 0xb8),&DAT_180016ae8);
      *(undefined8 *)(param_1 + 0x4f0) = uVar5;
      *(undefined8 *)(param_1 + 0x1c0) = *(undefined8 *)(param_1 + 0x4f0);
      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) | 4;
      uVar5 = FUN_180001ac0(param_1 + 0x168);
      *(undefined8 *)(param_1 + 0x540) = uVar5;
      uVar2 = FUN_1800016dc(*(longlong **)(param_1 + 0x1c0),*(undefined8 *)(param_1 + 0x540));
      *(undefined1 *)(param_1 + 0x550) = uVar2;
      if (*(char *)(param_1 + 0x550) == '\0') goto code_r0x00018000ea82;
      uVar5 = FUN_180001bb4('\0',*(undefined8 **)(param_1 + 0xb8),&DAT_180016ae8);
      *(undefined8 *)(param_1 + 0x560) = uVar5;
      *(undefined8 *)(param_1 + 0x1c8) = *(undefined8 *)(param_1 + 0x560);
      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) | 8;
      uVar5 = FUN_180001ac0(param_1 + 0x188);
      *(undefined8 *)(param_1 + 0x570) = uVar5;
      uVar2 = FUN_1800016dc(*(longlong **)(param_1 + 0x1c8),*(undefined8 *)(param_1 + 0x570));
      *(undefined1 *)(param_1 + 0x580) = uVar2;
      if (*(char *)(param_1 + 0x580) == '\0') goto code_r0x00018000ea82;
      *(undefined4 *)(param_1 + 0x200) = 0;
    }
    *(undefined1 *)(param_1 + 0x1a8) = *(undefined1 *)(param_1 + 0x200);
    if ((*(uint *)(param_1 + 0x3c8) & 8) != 0) {
      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) & 0xfffffff7;
      FUN_180001c34(*(longlong **)(param_1 + 0x1c8));
    }
    if ((*(uint *)(param_1 + 0x3c8) & 4) != 0) {
      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) & 0xfffffffb;
      FUN_180001c34(*(longlong **)(param_1 + 0x1c0));
    }
    if ((*(uint *)(param_1 + 0x3c8) & 2) != 0) {
      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) & 0xfffffffd;
      FUN_180001c34(*(longlong **)(param_1 + 0x1b8));
    }
    if ((*(uint *)(param_1 + 0x3c8) & 1) != 0) {
      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) & 0xfffffffe;
      FUN_180001c34(*(longlong **)(param_1 + 0x1b0));
    }
    if (*(char *)(param_1 + 0x1a8) != '\0') {
      pvVar7 = Platform::Details::Heap::AllocateException(0x68,0x80);
      *(void **)(param_1 + 0x590) = pvVar7;
      *(undefined8 *)(param_1 + 0x1d0) = *(undefined8 *)(param_1 + 0x590);
      uVar5 = Platform::Exception::Exception(*(Exception **)(param_1 + 0x1d0),-0x7ff8ffa9);
      *(undefined8 *)(param_1 + 0x5a0) = uVar5;
      *(undefined8 *)(param_1 + 0x1d8) = *(undefined8 *)(param_1 + 0x5a0);
      plVar6 = FUN_180001c50(*(longlong **)(param_1 + 0x1d8));
      *(longlong **)(param_1 + 0x5b0) = plVar6;
      auStack_1538[0] = *(undefined8 *)(param_1 + 0x5b0);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(auStack_1538,(ThrowInfo *)&DAT_18001aff0);
    }
    puStack_1528 = (undefined8 *)(param_1 + 0xb8);
    puStack_1520 = (undefined8 *)(param_1 + 0x5c0);
    uStack_1518 = FUN_180001bb4('\0',(undefined8 *)*puStack_1528,&DAT_180016ae8);
    *puStack_1520 = uStack_1518;
    puStack_1500 = (undefined8 *)(param_1 + 0x210);
    puStack_1510 = (undefined8 *)(param_1 + 0x5c0);
    uStack_1508 = *puStack_1510;
    *puStack_1500 = uStack_1508;
    lStack_14f0 = param_1 + 0x108;
    puStack_14e8 = (undefined8 *)(param_1 + 0x5d0);
    uStack_14f8 = uStack_1508;
    uStack_14e0 = FUN_180001ac0(lStack_14f0);
    *puStack_14e8 = uStack_14e0;
    puStack_14d8 = (undefined8 *)(param_1 + 0x5d0);
    uStack_14d0 = *puStack_14d8;
    puStack_14c8 = (undefined8 *)(param_1 + 0x210);
    puStack_14b8 = (undefined8 *)(param_1 + 0x5e0);
    uStack_14c0 = uStack_14d0;
    uStack_14b0 = FUN_180001654((longlong *)*puStack_14c8,uStack_14d0);
    *puStack_14b8 = uStack_14b0;
    puStack_1498 = (undefined8 *)(param_1 + 0x1f0);
    puStack_14a8 = (undefined8 *)(param_1 + 0x5e0);
    uStack_14a0 = *puStack_14a8;
    *puStack_1498 = uStack_14a0;
    puStack_1488 = (undefined8 *)(param_1 + 0x1f0);
    puStack_1480 = (undefined8 *)(param_1 + 0x5f0);
    uStack_1490 = uStack_14a0;
    uStack_1478 = func_0x00018000992c(0,*puStack_1488);
    *puStack_1480 = uStack_1478;
    puStack_1460 = (undefined8 *)(param_1 + 0x1e8);
    puStack_1470 = (undefined8 *)(param_1 + 0x5f0);
    uStack_1468 = *puStack_1470;
    *puStack_1460 = uStack_1468;
    plStack_1450 = (longlong *)(param_1 + 0x1e8);
    puStack_1448 = (undefined8 *)(param_1 + 0x600);
    uStack_1458 = uStack_1468;
    uStack_1440 = FUN_180001894(*plStack_1450);
    *puStack_1448 = uStack_1440;
    puStack_1428 = (undefined8 *)(param_1 + 0x1e0);
    puStack_1438 = (undefined8 *)(param_1 + 0x600);
    uStack_1430 = *puStack_1438;
    *puStack_1428 = uStack_1430;
    puStack_1418 = (undefined8 *)(param_1 + 0x1e8);
    uStack_1420 = uStack_1430;
    WindowsDeleteString(*puStack_1418);
    puStack_1410 = (undefined8 *)(param_1 + 0x1f0);
    FUN_180001c34((longlong *)*puStack_1410);
    puStack_1408 = (undefined8 *)(param_1 + 0x210);
    FUN_180001c34((longlong *)*puStack_1408);
    puStack_1400 = (undefined8 *)(param_1 + 0x1e0);
    puStack_13f8 = (undefined1 *)(param_1 + 0x610);
    uVar2 = FUN_18000c2bc(*puStack_1400);
    *puStack_13f8 = uVar2;
    pcStack_13f0 = (char *)(param_1 + 0x610);
    if (*pcStack_13f0 != '\0') {
code_r0x00018000f5fc:
      puStack_13d0 = (undefined8 *)(param_1 + 0x630);
      pvStack_13c8 = Platform::Details::Heap::AllocateException(0x68,0x80);
      *puStack_13d0 = pvStack_13c8;
      puStack_13b0 = (undefined8 *)(param_1 + 0x218);
      puStack_13c0 = (undefined8 *)(param_1 + 0x630);
      uStack_13b8 = *puStack_13c0;
      *puStack_13b0 = uStack_13b8;
      puStack_13a0 = (undefined8 *)(param_1 + 0x218);
      pEStack_1398 = (Exception *)*puStack_13a0;
      puStack_1390 = (undefined8 *)(param_1 + 0x640);
      uStack_13a8 = uStack_13b8;
      uStack_1388 = Platform::Exception::Exception(pEStack_1398,-0x7ff8ffa9);
      *puStack_1390 = uStack_1388;
      puStack_1370 = (undefined8 *)(param_1 + 0x220);
      puStack_1380 = (undefined8 *)(param_1 + 0x640);
      uStack_1378 = *puStack_1380;
      *puStack_1370 = uStack_1378;
      puStack_1360 = (undefined8 *)(param_1 + 0x220);
      plStack_1358 = (longlong *)*puStack_1360;
      puStack_1350 = (undefined8 *)(param_1 + 0x650);
      uStack_1368 = uStack_1378;
      plStack_1348 = FUN_180001c50(plStack_1358);
      *puStack_1350 = plStack_1348;
      puStack_1340 = (undefined8 *)(param_1 + 0x650);
      uStack_1338 = *puStack_1340;
      auStack_1330[0] = uStack_1338;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(auStack_1330,(ThrowInfo *)&DAT_18001aff0);
    }
    lStack_13e8 = param_1 + 0x1e0;
    lStack_13e0 = param_1 + 0x620;
    bVar3 = FUN_18000c2a8();
    *(bool *)lStack_13e0 = bVar3;
    pcStack_13d8 = (char *)(param_1 + 0x620);
    if (*pcStack_13d8 != '\0') goto code_r0x00018000f5fc;
    puStack_1320 = (undefined8 *)(param_1 + 0xb8);
    puStack_1318 = (undefined8 *)(param_1 + 0x660);
    uStack_1310 = FUN_180001bb4('\0',(undefined8 *)*puStack_1320,&DAT_180016ae8);
    *puStack_1318 = uStack_1310;
    puStack_12f8 = (undefined8 *)(param_1 + 0x240);
    puStack_1308 = (undefined8 *)(param_1 + 0x660);
    uStack_1300 = *puStack_1308;
    *puStack_12f8 = uStack_1300;
    lStack_12e8 = param_1 + 0x128;
    puStack_12e0 = (undefined8 *)(param_1 + 0x670);
    uStack_12f0 = uStack_1300;
    uStack_12d8 = FUN_180001ac0(lStack_12e8);
    *puStack_12e0 = uStack_12d8;
    puStack_12d0 = (undefined8 *)(param_1 + 0x670);
    uStack_12c8 = *puStack_12d0;
    puStack_12c0 = (undefined8 *)(param_1 + 0x240);
    puStack_12b0 = (undefined8 *)(param_1 + 0x680);
    uStack_12b8 = uStack_12c8;
    uStack_12a8 = FUN_180001654((longlong *)*puStack_12c0,uStack_12c8);
    *puStack_12b0 = uStack_12a8;
    puStack_1290 = (undefined8 *)(param_1 + 0x238);
    puStack_12a0 = (undefined8 *)(param_1 + 0x680);
    uStack_1298 = *puStack_12a0;
    *puStack_1290 = uStack_1298;
    puStack_1280 = (undefined8 *)(param_1 + 0x238);
    puStack_1278 = (undefined8 *)(param_1 + 0x690);
    uStack_1288 = uStack_1298;
    uStack_1270 = func_0x00018000992c(0,*puStack_1280);
    *puStack_1278 = uStack_1270;
    puStack_1258 = (undefined8 *)(param_1 + 0x230);
    puStack_1268 = (undefined8 *)(param_1 + 0x690);
    uStack_1260 = *puStack_1268;
    *puStack_1258 = uStack_1260;
    plStack_1248 = (longlong *)(param_1 + 0x230);
    puStack_1240 = (undefined8 *)(param_1 + 0x6a0);
    uStack_1250 = uStack_1260;
    uStack_1238 = FUN_180001894(*plStack_1248);
    *puStack_1240 = uStack_1238;
    puStack_1220 = (undefined8 *)(param_1 + 0x228);
    puStack_1230 = (undefined8 *)(param_1 + 0x6a0);
    uStack_1228 = *puStack_1230;
    *puStack_1220 = uStack_1228;
    puStack_1210 = (undefined8 *)(param_1 + 0x230);
    uStack_1218 = uStack_1228;
    WindowsDeleteString(*puStack_1210);
    puStack_1208 = (undefined8 *)(param_1 + 0x238);
    FUN_180001c34((longlong *)*puStack_1208);
    puStack_1200 = (undefined8 *)(param_1 + 0x240);
    FUN_180001c34((longlong *)*puStack_1200);
    puStack_11f8 = (undefined8 *)(param_1 + 0x228);
    puStack_11f0 = (undefined1 *)(param_1 + 0x6b0);
    uVar2 = FUN_18000c2bc(*puStack_11f8);
    *puStack_11f0 = uVar2;
    pcStack_11e8 = (char *)(param_1 + 0x6b0);
    if (*pcStack_11e8 != '\0') {
code_r0x00018000fdc6:
      puStack_11c8 = (undefined8 *)(param_1 + 0x6d0);
      pvStack_11c0 = Platform::Details::Heap::AllocateException(0x68,0x80);
      *puStack_11c8 = pvStack_11c0;
      puStack_11a8 = (undefined8 *)(param_1 + 0x248);
      puStack_11b8 = (undefined8 *)(param_1 + 0x6d0);
      uStack_11b0 = *puStack_11b8;
      *puStack_11a8 = uStack_11b0;
      puStack_1198 = (undefined8 *)(param_1 + 0x248);
      pEStack_1190 = (Exception *)*puStack_1198;
      puStack_1188 = (undefined8 *)(param_1 + 0x6e0);
      uStack_11a0 = uStack_11b0;
      uStack_1180 = Platform::Exception::Exception(pEStack_1190,-0x7ff8ffa9);
      *puStack_1188 = uStack_1180;
      puStack_1168 = (undefined8 *)(param_1 + 0x250);
      puStack_1178 = (undefined8 *)(param_1 + 0x6e0);
      uStack_1170 = *puStack_1178;
      *puStack_1168 = uStack_1170;
      puStack_1158 = (undefined8 *)(param_1 + 0x250);
      plStack_1150 = (longlong *)*puStack_1158;
      puStack_1148 = (undefined8 *)(param_1 + 0x6f0);
      uStack_1160 = uStack_1170;
      plStack_1140 = FUN_180001c50(plStack_1150);
      *puStack_1148 = plStack_1140;
      puStack_1138 = (undefined8 *)(param_1 + 0x6f0);
      uStack_1130 = *puStack_1138;
      auStack_1128[0] = uStack_1130;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(auStack_1128,(ThrowInfo *)&DAT_18001aff0);
    }
    lStack_11e0 = param_1 + 0x228;
    lStack_11d8 = param_1 + 0x6c0;
    bVar3 = FUN_18000c2a8();
    *(bool *)lStack_11d8 = bVar3;
    pcStack_11d0 = (char *)(param_1 + 0x6c0);
    if (*pcStack_11d0 != '\0') goto code_r0x00018000fdc6;
    puStack_1118 = (undefined8 *)(param_1 + 0xb8);
    puStack_1110 = (undefined8 *)(param_1 + 0x700);
    uStack_1108 = FUN_180001bb4('\0',(undefined8 *)*puStack_1118,&DAT_180016ae8);
    *puStack_1110 = uStack_1108;
    puStack_10f0 = (undefined8 *)(param_1 + 0x270);
    puStack_1100 = (undefined8 *)(param_1 + 0x700);
    uStack_10f8 = *puStack_1100;
    *puStack_10f0 = uStack_10f8;
    lStack_10e0 = param_1 + 0x168;
    puStack_10d8 = (undefined8 *)(param_1 + 0x710);
    uStack_10e8 = uStack_10f8;
    uStack_10d0 = FUN_180001ac0(lStack_10e0);
    *puStack_10d8 = uStack_10d0;
    puStack_10c8 = (undefined8 *)(param_1 + 0x710);
    uStack_10c0 = *puStack_10c8;
    puStack_10b8 = (undefined8 *)(param_1 + 0x270);
    puStack_10a8 = (undefined8 *)(param_1 + 0x720);
    uStack_10b0 = uStack_10c0;
    uStack_10a0 = FUN_180001654((longlong *)*puStack_10b8,uStack_10c0);
    *puStack_10a8 = uStack_10a0;
    puStack_1088 = (undefined8 *)(param_1 + 0x268);
    puStack_1098 = (undefined8 *)(param_1 + 0x720);
    uStack_1090 = *puStack_1098;
    *puStack_1088 = uStack_1090;
    puStack_1078 = (undefined8 *)(param_1 + 0x268);
    puStack_1070 = (undefined8 *)(param_1 + 0x730);
    uStack_1080 = uStack_1090;
    uStack_1068 = func_0x00018000992c(0,*puStack_1078);
    *puStack_1070 = uStack_1068;
    puStack_1050 = (undefined8 *)(param_1 + 0x260);
    puStack_1060 = (undefined8 *)(param_1 + 0x730);
    uStack_1058 = *puStack_1060;
    *puStack_1050 = uStack_1058;
    plStack_1040 = (longlong *)(param_1 + 0x260);
    puStack_1038 = (undefined8 *)(param_1 + 0x740);
    uStack_1048 = uStack_1058;
    uStack_1030 = FUN_180001894(*plStack_1040);
    *puStack_1038 = uStack_1030;
    puStack_1018 = (undefined8 *)(param_1 + 600);
    puStack_1028 = (undefined8 *)(param_1 + 0x740);
    uStack_1020 = *puStack_1028;
    *puStack_1018 = uStack_1020;
    puStack_1008 = (undefined8 *)(param_1 + 0x260);
    uStack_1010 = uStack_1020;
    WindowsDeleteString(*puStack_1008);
    puStack_1000 = (undefined8 *)(param_1 + 0x268);
    FUN_180001c34((longlong *)*puStack_1000);
    puStack_ff8 = (undefined8 *)(param_1 + 0x270);
    FUN_180001c34((longlong *)*puStack_ff8);
    puStack_ff0 = (undefined8 *)(param_1 + 600);
    puStack_fe8 = (undefined1 *)(param_1 + 0x750);
    uVar2 = FUN_18000c2bc(*puStack_ff0);
    *puStack_fe8 = uVar2;
    pcStack_fe0 = (char *)(param_1 + 0x750);
    if (*pcStack_fe0 != '\0') {
code_r0x000180010590:
      puStack_fc0 = (undefined8 *)(param_1 + 0x770);
      pvStack_fb8 = Platform::Details::Heap::AllocateException(0x68,0x80);
      *puStack_fc0 = pvStack_fb8;
      puStack_fa0 = (undefined8 *)(param_1 + 0x278);
      puStack_fb0 = (undefined8 *)(param_1 + 0x770);
      uStack_fa8 = *puStack_fb0;
      *puStack_fa0 = uStack_fa8;
      puStack_f90 = (undefined8 *)(param_1 + 0x278);
      pEStack_f88 = (Exception *)*puStack_f90;
      puStack_f80 = (undefined8 *)(param_1 + 0x780);
      uStack_f98 = uStack_fa8;
      uStack_f78 = Platform::Exception::Exception(pEStack_f88,-0x7ff8ffa9);
      *puStack_f80 = uStack_f78;
      puStack_f60 = (undefined8 *)(param_1 + 0x280);
      puStack_f70 = (undefined8 *)(param_1 + 0x780);
      uStack_f68 = *puStack_f70;
      *puStack_f60 = uStack_f68;
      puStack_f50 = (undefined8 *)(param_1 + 0x280);
      plStack_f48 = (longlong *)*puStack_f50;
      puStack_f40 = (undefined8 *)(param_1 + 0x790);
      uStack_f58 = uStack_f68;
      plStack_f38 = FUN_180001c50(plStack_f48);
      *puStack_f40 = plStack_f38;
      puStack_f30 = (undefined8 *)(param_1 + 0x790);
      uStack_f28 = *puStack_f30;
      auStack_f20[0] = uStack_f28;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(auStack_f20,(ThrowInfo *)&DAT_18001aff0);
    }
    lStack_fd8 = param_1 + 600;
    lStack_fd0 = param_1 + 0x760;
    bVar3 = FUN_18000c2a8();
    *(bool *)lStack_fd0 = bVar3;
    pcStack_fc8 = (char *)(param_1 + 0x760);
    if (*pcStack_fc8 != '\0') goto code_r0x000180010590;
    puStack_f10 = (undefined8 *)(param_1 + 0xb8);
    puStack_f08 = (undefined8 *)(param_1 + 0x7a0);
    uStack_f00 = FUN_180001bb4('\0',(undefined8 *)*puStack_f10,&DAT_180016ae8);
    *puStack_f08 = uStack_f00;
    puStack_ee8 = (undefined8 *)(param_1 + 0x2a0);
    puStack_ef8 = (undefined8 *)(param_1 + 0x7a0);
    uStack_ef0 = *puStack_ef8;
    *puStack_ee8 = uStack_ef0;
    lStack_ed8 = param_1 + 0x188;
    puStack_ed0 = (undefined8 *)(param_1 + 0x7b0);
    uStack_ee0 = uStack_ef0;
    uStack_ec8 = FUN_180001ac0(lStack_ed8);
    *puStack_ed0 = uStack_ec8;
    puStack_ec0 = (undefined8 *)(param_1 + 0x7b0);
    uStack_eb8 = *puStack_ec0;
    puStack_eb0 = (undefined8 *)(param_1 + 0x2a0);
    puStack_ea0 = (undefined8 *)(param_1 + 0x7c0);
    uStack_ea8 = uStack_eb8;
    uStack_e98 = FUN_180001654((longlong *)*puStack_eb0,uStack_eb8);
    *puStack_ea0 = uStack_e98;
    puStack_e80 = (undefined8 *)(param_1 + 0x298);
    puStack_e90 = (undefined8 *)(param_1 + 0x7c0);
    uStack_e88 = *puStack_e90;
    *puStack_e80 = uStack_e88;
    puStack_e70 = (undefined8 *)(param_1 + 0x298);
    puStack_e68 = (undefined8 *)(param_1 + 2000);
    uStack_e78 = uStack_e88;
    uStack_e60 = func_0x00018000992c(0,*puStack_e70);
    *puStack_e68 = uStack_e60;
    puStack_e48 = (undefined8 *)(param_1 + 0x290);
    puStack_e58 = (undefined8 *)(param_1 + 2000);
    uStack_e50 = *puStack_e58;
    *puStack_e48 = uStack_e50;
    plStack_e38 = (longlong *)(param_1 + 0x290);
    puStack_e30 = (undefined8 *)(param_1 + 0x7e0);
    uStack_e40 = uStack_e50;
    uStack_e28 = FUN_180001894(*plStack_e38);
    *puStack_e30 = uStack_e28;
    puStack_e10 = (undefined8 *)(param_1 + 0x288);
    puStack_e20 = (undefined8 *)(param_1 + 0x7e0);
    uStack_e18 = *puStack_e20;
    *puStack_e10 = uStack_e18;
    puStack_e00 = (undefined8 *)(param_1 + 0x290);
    uStack_e08 = uStack_e18;
    WindowsDeleteString(*puStack_e00);
    puStack_df8 = (undefined8 *)(param_1 + 0x298);
    FUN_180001c34((longlong *)*puStack_df8);
    puStack_df0 = (undefined8 *)(param_1 + 0x2a0);
    FUN_180001c34((longlong *)*puStack_df0);
    puStack_de8 = (undefined8 *)(param_1 + 0x288);
    puStack_de0 = (undefined1 *)(param_1 + 0x7f0);
    uVar2 = FUN_18000c2bc(*puStack_de8);
    *puStack_de0 = uVar2;
    pcStack_dd8 = (char *)(param_1 + 0x7f0);
    if (*pcStack_dd8 != '\0') {
code_r0x000180010d4e:
      puStack_db8 = (undefined8 *)(param_1 + 0x810);
      pvStack_db0 = Platform::Details::Heap::AllocateException(0x68,0x80);
      *puStack_db8 = pvStack_db0;
      puStack_d98 = (undefined8 *)(param_1 + 0x2a8);
      puStack_da8 = (undefined8 *)(param_1 + 0x810);
      uStack_da0 = *puStack_da8;
      *puStack_d98 = uStack_da0;
      puStack_d88 = (undefined8 *)(param_1 + 0x2a8);
      pEStack_d80 = (Exception *)*puStack_d88;
      puStack_d78 = (undefined8 *)(param_1 + 0x820);
      uStack_d90 = uStack_da0;
      uStack_d70 = Platform::Exception::Exception(pEStack_d80,-0x7ff8ffa9);
      *puStack_d78 = uStack_d70;
      puStack_d58 = (undefined8 *)(param_1 + 0x2b0);
      puStack_d68 = (undefined8 *)(param_1 + 0x820);
      uStack_d60 = *puStack_d68;
      *puStack_d58 = uStack_d60;
      puStack_d48 = (undefined8 *)(param_1 + 0x2b0);
      plStack_d40 = (longlong *)*puStack_d48;
      puStack_d38 = (undefined8 *)(param_1 + 0x830);
      uStack_d50 = uStack_d60;
      plStack_d30 = FUN_180001c50(plStack_d40);
      *puStack_d38 = plStack_d30;
      puStack_d28 = (undefined8 *)(param_1 + 0x830);
      uStack_d20 = *puStack_d28;
      auStack_d18[0] = uStack_d20;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(auStack_d18,(ThrowInfo *)&DAT_18001aff0);
    }
    lStack_dd0 = param_1 + 0x288;
    lStack_dc8 = param_1 + 0x800;
    bVar3 = FUN_18000c2a8();
    *(bool *)lStack_dc8 = bVar3;
    pcStack_dc0 = (char *)(param_1 + 0x800);
    if (*pcStack_dc0 != '\0') goto code_r0x000180010d4e;
    puStack_d08 = (undefined8 *)(param_1 + 0x2b8);
    uStack_d00 = 0;
    *puStack_d08 = 0;
    puStack_cf8 = (undefined8 *)(param_1 + 0xb8);
    puStack_cf0 = (undefined8 *)(param_1 + 0x840);
    uStack_ce8 = FUN_180001bb4('\0',(undefined8 *)*puStack_cf8,&DAT_180016ae8);
    *puStack_cf0 = uStack_ce8;
    puStack_cd0 = (undefined8 *)(param_1 + 0x2c8);
    puStack_ce0 = (undefined8 *)(param_1 + 0x840);
    uStack_cd8 = *puStack_ce0;
    *puStack_cd0 = uStack_cd8;
    lStack_cc0 = param_1 + 0x148;
    puStack_cb8 = (undefined8 *)(param_1 + 0x850);
    uStack_cc8 = uStack_cd8;
    uStack_cb0 = FUN_180001ac0(lStack_cc0);
    *puStack_cb8 = uStack_cb0;
    puStack_ca8 = (undefined8 *)(param_1 + 0x850);
    uStack_ca0 = *puStack_ca8;
    puStack_c98 = (undefined8 *)(param_1 + 0x2c8);
    puStack_c88 = (undefined1 *)(param_1 + 0x860);
    uStack_c90 = uStack_ca0;
    uVar2 = FUN_1800016dc((longlong *)*puStack_c98,uStack_ca0);
    *puStack_c88 = uVar2;
    puStack_c78 = (undefined1 *)(param_1 + 0x2c0);
    puStack_c80 = (undefined1 *)(param_1 + 0x860);
    *puStack_c78 = *puStack_c80;
    puStack_c70 = (undefined8 *)(param_1 + 0x2c8);
    FUN_180001c34((longlong *)*puStack_c70);
    pcStack_c68 = (char *)(param_1 + 0x2c0);
    if (*pcStack_c68 != '\0') {
      puStack_c60 = (undefined8 *)(param_1 + 0xb8);
      puStack_c58 = (undefined8 *)(param_1 + 0x870);
      uStack_c50 = FUN_180001bb4('\0',(undefined8 *)*puStack_c60,&DAT_180016ae8);
      *puStack_c58 = uStack_c50;
      puStack_c38 = (undefined8 *)(param_1 + 0x2e0);
      puStack_c48 = (undefined8 *)(param_1 + 0x870);
      uStack_c40 = *puStack_c48;
      *puStack_c38 = uStack_c40;
      lStack_c28 = param_1 + 0x148;
      puStack_c20 = (undefined8 *)(param_1 + 0x880);
      uStack_c30 = uStack_c40;
      uStack_c18 = FUN_180001ac0(lStack_c28);
      *puStack_c20 = uStack_c18;
      puStack_c10 = (undefined8 *)(param_1 + 0x880);
      uStack_c08 = *puStack_c10;
      puStack_c00 = (undefined8 *)(param_1 + 0x2e0);
      puStack_bf0 = (undefined8 *)(param_1 + 0x890);
      uStack_bf8 = uStack_c08;
      uStack_be8 = FUN_180001654((longlong *)*puStack_c00,uStack_c08);
      *puStack_bf0 = uStack_be8;
      puStack_bd0 = (undefined8 *)(param_1 + 0x2d8);
      puStack_be0 = (undefined8 *)(param_1 + 0x890);
      uStack_bd8 = *puStack_be0;
      *puStack_bd0 = uStack_bd8;
      puStack_bc0 = (undefined8 *)(param_1 + 0x2d8);
      puStack_bb8 = (undefined8 *)(param_1 + 0x8a0);
      uStack_bc8 = uStack_bd8;
      uStack_bb0 = func_0x00018000992c(CONCAT71((int7)((ulonglong)uStack_bd8 >> 8),1),*puStack_bc0);
      *puStack_bb8 = uStack_bb0;
      puStack_b98 = (undefined8 *)(param_1 + 0x2d0);
      puStack_ba8 = (undefined8 *)(param_1 + 0x8a0);
      uStack_ba0 = *puStack_ba8;
      *puStack_b98 = uStack_ba0;
      plStack_b88 = (longlong *)(param_1 + 0x2d0);
      plStack_b80 = (longlong *)(param_1 + 0x2b8);
      uStack_b90 = uStack_ba0;
      FUN_1800098b4(plStack_b80,*plStack_b88);
      puStack_b78 = (undefined8 *)(param_1 + 0x2d0);
      WindowsDeleteString(*puStack_b78);
      puStack_b70 = (undefined8 *)(param_1 + 0x2d8);
      FUN_180001c34((longlong *)*puStack_b70);
      puStack_b68 = (undefined8 *)(param_1 + 0x2e0);
      FUN_180001c34((longlong *)*puStack_b68);
    }
    puStack_b60 = (undefined8 *)(param_1 + 0x288);
    puStack_b58 = (undefined8 *)(param_1 + 600);
    in_R9 = *puStack_b58;
    psStack_b50 = (size_t *)(param_1 + 0x2b8);
    sStack_330 = *psStack_b50;
    puStack_b48 = (undefined8 *)(param_1 + 0x228);
    puStack_b40 = (undefined8 *)(param_1 + 0x1e0);
    FUN_1800059bc(*puStack_b40,*puStack_b48,sStack_330,in_R9,*puStack_b60);
    puStack_b38 = (undefined8 *)(param_1 + 0xd0);
    puStack_b30 = (undefined8 *)(param_1 + 0x8b0);
    uStack_b28 = FUN_180001bb4('\0',(undefined8 *)*puStack_b38,&DAT_180016ae8);
    *puStack_b30 = uStack_b28;
    puStack_b10 = (undefined8 *)(param_1 + 0x2e8);
    puStack_b20 = (undefined8 *)(param_1 + 0x8b0);
    uStack_b18 = *puStack_b20;
    *puStack_b10 = uStack_b18;
    pvStack_b00 = (void *)(param_1 + 0x2f8);
    puStack_af8 = (undefined8 *)(param_1 + 0x8c0);
    uStack_b08 = uStack_b18;
    pvStack_af0 = FUN_180001a50(pvStack_b00,L"Success");
    *puStack_af8 = pvStack_af0;
    plStack_ae8 = (longlong *)(param_1 + 0x8c0);
    lStack_ae0 = *plStack_ae8;
    puStack_ad0 = (undefined8 *)(param_1 + 0x8d0);
    lStack_ad8 = lStack_ae0;
    uStack_ac8 = FUN_180001ac0(lStack_ae0);
    *puStack_ad0 = uStack_ac8;
    puStack_ac0 = (undefined8 *)(param_1 + 0x8d0);
    pSStack_ab8 = (String *)*puStack_ac0;
    puStack_ab0 = (undefined8 *)(param_1 + 0x8e0);
    uStack_aa8 = FUN_1800098a8(0,pSStack_ab8);
    *puStack_ab0 = uStack_aa8;
    puStack_a90 = (undefined8 *)(param_1 + 0x2f0);
    puStack_aa0 = (undefined8 *)(param_1 + 0x8e0);
    uStack_a98 = *puStack_aa0;
    *puStack_a90 = uStack_a98;
    puStack_a78 = (undefined8 *)(param_1 + 0x3d0);
    puStack_a80 = (undefined8 *)(param_1 + 0x2f0);
    uStack_a70 = *puStack_a80;
    *puStack_a78 = uStack_a70;
    lStack_a68 = param_1 + 0xe8;
    puStack_a60 = (undefined8 *)(param_1 + 0x8f0);
    uStack_a88 = uStack_a98;
    uStack_a58 = FUN_180001ac0(lStack_a68);
    *puStack_a60 = uStack_a58;
    puStack_a50 = (undefined8 *)(param_1 + 0x8f0);
    uStack_a48 = *puStack_a50;
    puStack_a40 = (undefined8 *)(param_1 + 0x3d0);
    in_R8 = *puStack_a40;
    puStack_a38 = (undefined8 *)(param_1 + 0x2e8);
    uStack_a30 = in_R8;
    uStack_a28 = uStack_a48;
    FUN_180001724((longlong *)*puStack_a38);
    puStack_a20 = (undefined8 *)(param_1 + 0x2f0);
    FUN_180001c34((longlong *)*puStack_a20);
    lStack_a18 = param_1 + 0x2f8;
    FUN_180001a44(lStack_a18);
    puStack_a10 = (undefined8 *)(param_1 + 0x2e8);
    FUN_180001c34((longlong *)*puStack_a10);
    puStack_a08 = (undefined8 *)(param_1 + 0x2b8);
    sStack_330 = *puStack_a08;
    WindowsDeleteString(sStack_330);
    puStack_a00 = (undefined8 *)(param_1 + 0x288);
    WindowsDeleteString(*puStack_a00);
    puStack_9f8 = (undefined8 *)(param_1 + 600);
    WindowsDeleteString(*puStack_9f8);
    puStack_9f0 = (undefined8 *)(param_1 + 0x228);
    WindowsDeleteString(*puStack_9f0);
    puStack_9e8 = (undefined8 *)(param_1 + 0x1e0);
    WindowsDeleteString(*puStack_9e8);
    puStack_6f8 = (undefined8 *)(param_1 + 0x9e0);
    uStack_6f0 = FUN_18000176c(*(longlong **)(param_1 + 0xa71));
    *puStack_6f8 = uStack_6f0;
    puStack_6d8 = (undefined8 *)(param_1 + 0x388);
    puStack_6e8 = (undefined8 *)(param_1 + 0x9e0);
    uStack_6e0 = *puStack_6e8;
    *puStack_6d8 = uStack_6e0;
    puStack_6c8 = (undefined8 *)(param_1 + 0xd0);
    puStack_6c0 = (undefined8 *)(param_1 + 0x388);
    puStack_6b8 = (undefined8 *)(param_1 + 0x9f0);
    uStack_6d0 = uStack_6e0;
    uStack_6b0 = FUN_180008354((longlong *)*puStack_6c0,*puStack_6c8);
    *puStack_6b8 = uStack_6b0;
    puStack_698 = (undefined8 *)(param_1 + 0x380);
    puStack_6a8 = (undefined8 *)(param_1 + 0x9f0);
    uStack_6a0 = *puStack_6a8;
    *puStack_698 = uStack_6a0;
    puStack_688 = (undefined8 *)(param_1 + 0x380);
    in_RDX = (longlong *)*puStack_688;
    puStack_680 = (undefined8 *)(param_1 + 0x390);
    puStack_678 = (undefined8 *)(param_1 + 0xa00);
    uStack_690 = uStack_6a0;
    puStack_670 = FUN_180006690(puStack_680,in_RDX);
    *puStack_678 = puStack_670;
    puStack_668 = (undefined8 *)(param_1 + 0xa00);
    uStack_660 = *puStack_668;
    puStack_650 = (undefined8 *)(param_1 + 0x378);
    *puStack_650 = uStack_660;
    puStack_640 = (undefined8 *)(param_1 + 0x378);
    puStack_638 = (undefined1 *)(param_1 + 0xa10);
    uStack_658 = uStack_660;
    uStack_648 = uStack_660;
    uVar2 = FUN_180007e44((longlong *)*puStack_640);
    *puStack_638 = uVar2;
    pcStack_630 = (char *)(param_1 + 0xa10);
    if (*pcStack_630 == '\0') {
      puStack_620 = (undefined8 *)(param_1 + 0x398);
      puVar8 = FUN_180007b90(puStack_620,param_1);
      uStack_618 = *puVar8;
      puStack_610 = (undefined8 *)(param_1 + 0x3a0);
      *puStack_610 = uStack_618;
      puStack_600 = (undefined2 *)(param_1 + 8);
      *puStack_600 = 4;
      puStack_5f8 = (undefined8 *)(param_1 + 0x3a0);
      uStack_5e8 = *puStack_5f8;
      puStack_5f0 = (undefined8 *)(param_1 + 0x378);
      uStack_608 = uStack_618;
      FUN_180007b98((undefined8 *)*puStack_5f0,uStack_5e8,in_R8,in_R9);
      goto LAB_18001297e;
    }
    puStack_628 = (undefined4 *)(param_1 + 0x400);
    *puStack_628 = 0;
    goto code_r0x00018001232a;
  case 3:
    break;
  case 4:
    puStack_570 = (undefined4 *)(param_1 + 0x400);
    *puStack_570 = 0;
code_r0x00018001232a:
    puStack_568 = (undefined8 *)(param_1 + 0x378);
    FUN_1800076d8((longlong *)*puStack_568);
    plStack_560 = (longlong *)(param_1 + 0x390);
    FUN_180007a34(plStack_560);
    puStack_558 = (undefined8 *)(param_1 + 0x380);
    FUN_180001c34((longlong *)*puStack_558);
    puStack_550 = (undefined8 *)(param_1 + 0x388);
    FUN_180001c34((longlong *)*puStack_550);
    lStack_4a8 = param_1 + 0x188;
    FUN_180001a44(lStack_4a8);
    lStack_4a0 = param_1 + 0x168;
    FUN_180001a44(lStack_4a0);
    lStack_498 = param_1 + 0x148;
    FUN_180001a44(lStack_498);
    lStack_490 = param_1 + 0x128;
    FUN_180001a44(lStack_490);
    lStack_488 = param_1 + 0x108;
    FUN_180001a44(lStack_488);
    lStack_480 = param_1 + 0xe8;
    FUN_180001a44(lStack_480);
    puStack_478 = (undefined8 *)(param_1 + 0xd0);
    FUN_180001c34((longlong *)*puStack_478);
    puStack_470 = (undefined8 *)(param_1 + 0xb8);
    FUN_180001c34((longlong *)*puStack_470);
    plStack_468 = (longlong *)(param_1 + 0x70);
    FUN_180009984(plStack_468);
    puStack_460 = (undefined8 *)(param_1 + 0x60);
    plStack_328 = (longlong *)*puStack_460;
    FUN_180001c34(plStack_328);
    pwStack_458 = (wchar_t *)(param_1 + 0x10);
    FUN_1800012bc(pwStack_458);
    FUN_180007f30((longlong *)(param_1 + -0x10),in_RDX,in_R8,in_R9);
    lStack_440 = param_1 + -0x10;
    puStack_448 = (undefined1 *)(param_1 + 0x3b0);
    puStack_430 = FUN_180008084(lStack_440,puStack_448);
    puStack_438 = (undefined8 *)(param_1 + 0x3a8);
    *puStack_438 = puStack_430;
    lStack_428 = param_1 + 0x3a8;
    cVar4 = FUN_1800099bc();
    if (cVar4 == '\0') {
      puStack_418 = (undefined8 *)(param_1 + 0x3b8);
      puVar8 = FUN_180007b90(puStack_418,param_1);
      uStack_410 = *puVar8;
      puStack_408 = (undefined8 *)(param_1 + 0x3c0);
      *puStack_408 = uStack_410;
      puStack_3f8 = (undefined2 *)(param_1 + 8);
      *puStack_3f8 = 0;
      puStack_3f0 = (undefined8 *)(param_1 + 0x3c0);
      uStack_3e0 = *puStack_3f0;
      lStack_3e8 = param_1 + 0x3a8;
      uStack_400 = uStack_410;
      _guard_check_icall();
      goto LAB_18001297e;
    }
    puStack_420 = (undefined4 *)(param_1 + 0x410);
    *puStack_420 = 0;
    lStack_3d0 = param_1 + 0x3a8;
    _guard_check_icall();
    break;
  case 5:
    plStack_5e0 = (longlong *)(param_1 + 0x390);
    FUN_180007a34(plStack_5e0);
    puStack_5d8 = (undefined8 *)(param_1 + 0x380);
    FUN_180001c34((longlong *)*puStack_5d8);
    puStack_5d0 = (undefined8 *)(param_1 + 0x388);
    FUN_180001c34((longlong *)*puStack_5d0);
    lStack_5c8 = param_1 + 0x188;
    FUN_180001a44(lStack_5c8);
    lStack_5c0 = param_1 + 0x168;
    FUN_180001a44(lStack_5c0);
    lStack_5b8 = param_1 + 0x148;
    FUN_180001a44(lStack_5b8);
    lStack_5b0 = param_1 + 0x128;
    FUN_180001a44(lStack_5b0);
    lStack_5a8 = param_1 + 0x108;
    FUN_180001a44(lStack_5a8);
    lStack_5a0 = param_1 + 0xe8;
    FUN_180001a44(lStack_5a0);
    puStack_598 = (undefined8 *)(param_1 + 0xd0);
    FUN_180001c34((longlong *)*puStack_598);
    puStack_590 = (undefined8 *)(param_1 + 0xb8);
    FUN_180001c34((longlong *)*puStack_590);
    plStack_588 = (longlong *)(param_1 + 0x70);
    FUN_180009984(plStack_588);
    puStack_580 = (undefined8 *)(param_1 + 0x60);
    plStack_328 = (longlong *)*puStack_580;
    FUN_180001c34(plStack_328);
    pwStack_578 = (wchar_t *)(param_1 + 0x10);
    FUN_1800012bc(pwStack_578);
    break;
  case 0xffff:
    break;
  }
  FUN_180007aa8(param_1 + -0x10);
  FUN_180007a54((longlong *)(param_1 + 0xa61));
  if (*(short *)(param_1 + 10) != 0) {
    puStack_3c8 = (undefined8 *)(param_1 + 0x430);
    uStack_3c0 = 0xa89;
    *puStack_3c8 = 0xa89;
    lStack_3a0 = param_1 + -0x10;
    plStack_3a8 = (longlong *)(param_1 + 0x420);
    *plStack_3a8 = lStack_3a0;
    lStack_398 = param_1 + 0x430;
    puStack_390 = (undefined8 *)(param_1 + 0x420);
    free((void *)*puStack_390);
  }
LAB_18001297e:
  FUN_18000c7f0(local_10 ^ (ulonglong)auStackY_1d88);
  return;
}


/* Function 1800129b4 __GSHandlerCheck */

/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,ulonglong param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4,*(uint **)(param_4 + 0x38));
  return 1;
}


/* Function 1800129d4 __GSHandlerCheckCommon */

/* Library Function - Single Match
    __GSHandlerCheckCommon
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __GSHandlerCheckCommon(ulonglong param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = param_1;
  if ((*param_3 & 4) != 0) {
    uVar2 = (longlong)(int)param_3[1] + param_1 & (longlong)(int)-param_3[2];
  }
  uVar1 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  if ((*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xf) != 0) {
    param_1 = param_1 + (*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xfffffff0);
  }
  FUN_18000c7f0(param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar2));
  return;
}


/* Function 180012a30 FID_conflict:__GSHandlerCheck_EH */

/* Library Function - Multiple Matches With Different Base Names
    __GSHandlerCheck_EH
    __GSHandlerCheck_EH4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void FID_conflict___GSHandlerCheck_EH
               (longlong param_1,ulonglong param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  __GSHandlerCheckCommon(param_2,param_4,(uint *)(lVar1 + 4));
  if ((*(uint *)(lVar1 + 4) & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {
    __CxxFrameHandler4(param_1,param_2,param_3,param_4);
  }
  return;
}


/* Function 180012ac0 __chkstk */

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __chkstk
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __chkstk(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    puVar2 = (undefined1 *)StackLimit;
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}


/* Function 180012b0e memcpy */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180012b0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}


/* Function 180012b14 memmove */

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180012b14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}


/* Function 180012b30 _guard_dispatch_icall */

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180012b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* Function 180012b50 _guard_dispatch_icall */

/* WARNING: This is an inlined function */
/* WARNING: Switch with 1 destination removed at 0x000180012b50 */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180012b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* Function 180012c32 FUN_180012c32 */

void FUN_180012c32(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x28) & 2) != 0) {
    *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) & 0xfffffffd;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_2 + 0x128));
  }
  return;
}


/* Function 180012cbd FUN_180012cbd */

void FUN_180012cbd(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x38) & 1) != 0) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffe;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(longlong *)(param_2 + 0x30) + 0x88));
  }
  return;
}


/* Function 180012d09 FUN_180012d09 */

void FUN_180012d09(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    FUN_1800015f0(*(longlong **)(param_2 + 0x48));
  }
  return;
}


/* Function 180012d3b FUN_180012d3b */

undefined8 FUN_180012d3b(undefined8 param_1,longlong param_2)

{
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             ((longlong)*(int *)(**(longlong **)(param_2 + 0x60) + 4) +
             (longlong)*(longlong **)(param_2 + 0x60)),4,true);
  return 0;
}


/* Function 180012d8e FUN_180012d8e */

undefined8 FUN_180012d8e(undefined8 param_1,longlong param_2)

{
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             ((longlong)*(int *)(**(longlong **)(param_2 + 0x90) + 4) +
             (longlong)*(longlong **)(param_2 + 0x90)),4,true);
  return 0;
}


/* Function 180012e46 FUN_180012e46 */

void FUN_180012e46(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    FUN_1800015f0(*(longlong **)(param_2 + 0x48));
  }
  return;
}


/* Function 180012fc8 FUN_180012fc8 */

void FUN_180012fc8(void)

{
  _guard_check_icall();
  return;
}


/* Function 18001307e FUN_18001307e */

void FUN_18001307e(void)

{
  _guard_check_icall();
  return;
}


/* Function 1800130b3 FUN_1800130b3 */

void FUN_1800130b3(void)

{
  _guard_check_icall();
  return;
}


/* Function 18001310c FUN_18001310c */

void FUN_18001310c(void)

{
  _guard_check_icall();
  return;
}


/* Function 180013135 FUN_180013135 */

undefined8 FUN_180013135(undefined8 param_1,longlong param_2)

{
  long lVar1;
  
  lVar1 = __abi_translateCurrentException(false);
  *(long *)(param_2 + 0x30) = lVar1;
  return 0;
}


/* Function 18001315e FUN_18001315e */

void FUN_18001315e(void)

{
  _guard_check_icall();
  return;
}


/* Function 180013187 FUN_180013187 */

void FUN_180013187(void)

{
  _guard_check_icall();
  return;
}


/* Function 1800131c8 FUN_1800131c8 */

undefined8 FUN_1800131c8(undefined8 param_1,longlong param_2)

{
  long lVar1;
  
  lVar1 = __abi_translateCurrentException(false);
  *(long *)(param_2 + 0x30) = lVar1;
  return 0;
}


/* Function 1800132b3 FUN_1800132b3 */

void FUN_1800132b3(void)

{
  _guard_check_icall();
  return;
}


/* Function 180013314 FUN_180013314 */

void FUN_180013314(undefined8 param_1,longlong param_2)

{
  FUN_1800092fc(*(undefined8 **)(param_2 + 0x20),
                (undefined8 *)(*(longlong *)(param_2 + 0x50) + 0x28));
  return;
}


/* Function 180013364 FUN_180013364 */

void FUN_180013364(void)

{
  _guard_check_icall();
  return;
}


/* Function 1800133e1 FUN_1800133e1 */

void FUN_1800133e1(undefined8 param_1,longlong param_2)

{
  free(*(void **)(param_2 + 0x90));
  return;
}


/* Function 180013411 FUN_180013411 */

undefined8 FUN_180013411(undefined8 param_1,longlong param_2)

{
  *(undefined ***)(param_2 + 0x20) = std::exception::vftable;
  __std_exception_destroy(param_2 + 0x28);
  return 0;
}


/* Function 180013445 FUN_180013445 */

undefined8 FUN_180013445(undefined8 param_1,longlong param_2)

{
  *(undefined ***)(param_2 + 0x38) = std::exception::vftable;
  __std_exception_destroy(param_2 + 0x40);
  return 0;
}


/* Function 180013479 FUN_180013479 */

undefined8 FUN_180013479(undefined8 param_1,longlong param_2)

{
  *(undefined ***)(param_2 + 0x50) = std::exception::vftable;
  __std_exception_destroy(param_2 + 0x58);
  return 0;
}


/* Function 1800134ad FUN_1800134ad */

undefined8 FUN_1800134ad(void)

{
  return 0;
}


/* Function 18001352b FUN_18001352b */

void FUN_18001352b(undefined8 param_1,longlong param_2)

{
  free(*(void **)(param_2 + 0x20));
  return;
}


/* Function 18001356c FUN_18001356c */

void FUN_18001356c(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    FUN_18000b9a4((_ContextCallback *)(param_2 + 0x28));
  }
  return;
}


/* Function 1800135aa FUN_1800135aa */

undefined8 FUN_1800135aa(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_2 + 0xe8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined8 *)(param_2 + 0x40) = 0;
  __ExceptionPtrCreate((void *)(param_2 + 0x38));
  __ExceptionPtrCurrentException((void *)(param_2 + 0x38));
  FUN_18000b7b0(plVar1,(void *)(param_2 + 0x38));
  __ExceptionPtrDestroy((void *)(param_2 + 0x38));
  return 0;
}


/* Function 180013635 FUN_180013635 */

void FUN_180013635(undefined8 param_1,longlong param_2)

{
  free(*(void **)(param_2 + 0x40));
  return;
}


/* Function 18001367a FUN_18001367a */

undefined8 FUN_18001367a(void)

{
  return 0;
}


/* Function 180013698 FUN_180013698 */

undefined8 FUN_180013698(void)

{
  return 0;
}


/* Function 1800136b6 FUN_1800136b6 */

undefined8 FUN_1800136b6(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_2 + 0x20);
  if (plVar1[2] == 0) {
    *(undefined8 *)(param_2 + 0x20) = 0;
    *(undefined8 *)(param_2 + 0x28) = 0;
    __ExceptionPtrCreate((void *)(param_2 + 0x20));
    __ExceptionPtrCurrentException((void *)(param_2 + 0x20));
    FUN_18000b7b0(plVar1,(void *)(param_2 + 0x20));
    __ExceptionPtrDestroy((void *)(param_2 + 0x20));
  }
  return 0;
}


/* Function 180013786 FUN_180013786 */

void FUN_180013786(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    FUN_18000b750(param_2 + 0xd0);
  }
  return;
}


/* Function 1800137af FUN_1800137af */

void FUN_1800137af(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 2) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffd;
    FUN_18000b750(param_2 + 0x80);
  }
  return;
}


/* Function 1800137fc FUN_1800137fc */

bool FUN_1800137fc(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}


/* Function 180013814 FUN_180013814 */

void FUN_180013814(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}


/* Function 18001382b FUN_18001382b */

void FUN_18001382b(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}


/* Function 180013844 FUN_180013844 */

void FUN_180013844(void)

{
  __scrt_dllmain_uninitialize_critical();
  return;
}


/* Function 180013858 FUN_180013858 */

void FUN_180013858(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_18000cd30,*(undefined4 *)*param_1,param_1);
  return;
}


/* Function 18001388e FUN_18001388e */

/* WARNING: Removing unreachable block (ram,0x0001800138be) */

void FUN_18001388e(undefined8 param_1,longlong param_2)

{
  if (*(short *)(*(longlong *)(param_2 + 0x98) + 10) != 0) {
    *(undefined8 *)(param_2 + 0x68) = 0x29;
    *(longlong *)(param_2 + 0x70) = *(longlong *)(param_2 + 0x98) + -0x10;
    free(*(void **)(param_2 + 0x70));
  }
  return;
}


/* Function 180013903 FUN_180013903 */

void FUN_180013903(undefined8 param_1,longlong param_2)

{
  FUN_180007a54((longlong *)(*(longlong *)(param_2 + 0x98) + 1));
  return;
}


/* Function 180013926 FUN_180013926 */

void FUN_180013926(undefined8 param_1,longlong param_2)

{
  FUN_180007aa8(*(longlong *)(param_2 + 0x98) + -0x10);
  return;
}


/* Function 180013945 FUN_180013945 */

void FUN_180013945(undefined8 param_1,longlong param_2)

{
  FUN_180007aa8(*(longlong *)(param_2 + 0xa0));
  return;
}


/* Function 180013960 FUN_180013960 */

void FUN_180013960(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1a68) = *(longlong *)(param_2 + 0x1d90) + 0x10;
  FUN_1800012bc(*(wchar_t **)(param_2 + 0x1a68));
  return;
}


/* Function 18001398e FUN_18001398e */

void FUN_18001398e(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1a70) = *(longlong *)(param_2 + 0x1d90) + 0x68;
  *(undefined8 *)(param_2 + 0x100) = **(undefined8 **)(param_2 + 0x1a70);
  FUN_180001c34(*(longlong **)(param_2 + 0x100));
  return;
}


/* Function 1800139cd FUN_1800139cd */

void FUN_1800139cd(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1a78) = *(longlong *)(param_2 + 0x1d90) + 0x60;
  *(undefined8 *)(param_2 + 0x1a60) = **(undefined8 **)(param_2 + 0x1a78);
  FUN_180001c34(*(longlong **)(param_2 + 0x1a60));
  return;
}


/* Function 180013a0c FUN_180013a0c */

void FUN_180013a0c(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1a80) = *(longlong *)(param_2 + 0x1d90) + 0xb0;
  FUN_180007a08(*(longlong **)(param_2 + 0x1a80));
  return;
}


/* Function 180013a3a FUN_180013a3a */

void FUN_180013a3a(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1a88) = *(longlong *)(param_2 + 0x1d90) + 0x70;
  FUN_180009984(*(longlong **)(param_2 + 0x1a88));
  return;
}


/* Function 180013a68 FUN_180013a68 */

void FUN_180013a68(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1a90) = *(longlong *)(param_2 + 0x1d90) + 200;
  *(undefined8 *)(param_2 + 0x110) = **(undefined8 **)(param_2 + 0x1a90);
  FUN_180001c34(*(longlong **)(param_2 + 0x110));
  return;
}


/* Function 180013aa7 FUN_180013aa7 */

void FUN_180013aa7(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1a98) = *(longlong *)(param_2 + 0x1d90) + 0xc0;
  *(undefined8 *)(param_2 + 0x108) = **(undefined8 **)(param_2 + 0x1a98);
  FUN_180001c34(*(longlong **)(param_2 + 0x108));
  return;
}


/* Function 180013ae6 FUN_180013ae6 */

void FUN_180013ae6(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1aa0) = *(longlong *)(param_2 + 0x1d90) + 0xb8;
  *(undefined8 *)(param_2 + 0x38) = **(undefined8 **)(param_2 + 0x1aa0);
  FUN_180001c34(*(longlong **)(param_2 + 0x38));
  return;
}


/* Function 180013b1f FUN_180013b1f */

void FUN_180013b1f(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1aa8) = *(longlong *)(param_2 + 0x1d90) + 0xd8;
  *(undefined8 *)(param_2 + 1000) = **(undefined8 **)(param_2 + 0x1aa8);
  _guard_check_icall();
  return;
}


/* Function 180013b60 FUN_180013b60 */

void FUN_180013b60(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *(longlong *)(param_2 + 0x1ab0) = *(longlong *)(param_2 + 0x1d90) + 0xe0;
  uVar1 = **(undefined8 **)(param_2 + 0x1ab0);
  *(longlong *)(param_2 + 0x1ab8) = *(longlong *)(param_2 + 0x1d90) + 0xe0;
  *(undefined8 *)(param_2 + 0x1ac0) = uVar1;
  **(undefined8 **)(param_2 + 0x1ab8) = *(undefined8 *)(param_2 + 0x1ac0);
  *(longlong *)(param_2 + 0x1ac8) = *(longlong *)(param_2 + 0x1d90) + 0xe0;
  *(undefined8 *)(param_2 + 0x118) = **(undefined8 **)(param_2 + 0x1ac8);
  FUN_180001c34(*(longlong **)(param_2 + 0x118));
  return;
}


/* Function 180013be7 FUN_180013be7 */

void FUN_180013be7(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1ad0) = *(longlong *)(param_2 + 0x1d90) + 0xd0;
  *(undefined8 *)(param_2 + 0x68) = **(undefined8 **)(param_2 + 0x1ad0);
  FUN_180001c34(*(longlong **)(param_2 + 0x68));
  return;
}


/* Function 180013c20 FUN_180013c20 */

void FUN_180013c20(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1ad8) = *(longlong *)(param_2 + 0x1d90) + 0xe8;
  FUN_180001a44(*(longlong *)(param_2 + 0x1ad8));
  return;
}


/* Function 180013c4e FUN_180013c4e */

void FUN_180013c4e(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1ae0) = *(longlong *)(param_2 + 0x1d90) + 0x108;
  FUN_180001a44(*(longlong *)(param_2 + 0x1ae0));
  return;
}


/* Function 180013c7c FUN_180013c7c */

void FUN_180013c7c(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1ae8) = *(longlong *)(param_2 + 0x1d90) + 0x128;
  FUN_180001a44(*(longlong *)(param_2 + 0x1ae8));
  return;
}


/* Function 180013caa FUN_180013caa */

void FUN_180013caa(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1af0) = *(longlong *)(param_2 + 0x1d90) + 0x148;
  FUN_180001a44(*(longlong *)(param_2 + 0x1af0));
  return;
}


/* Function 180013cd8 FUN_180013cd8 */

void FUN_180013cd8(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1af8) = *(longlong *)(param_2 + 0x1d90) + 0x168;
  FUN_180001a44(*(longlong *)(param_2 + 0x1af8));
  return;
}


/* Function 180013d06 FUN_180013d06 */

void FUN_180013d06(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1b00) = *(longlong *)(param_2 + 0x1d90) + 0x188;
  FUN_180001a44(*(longlong *)(param_2 + 0x1b00));
  return;
}


/* Function 180013d34 FUN_180013d34 */

void FUN_180013d34(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1b08) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
  *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 0x1b08);
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(longlong *)(param_2 + 0x1b10) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(longlong *)(param_2 + 0x1b18) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 0x1b18);
    *(uint *)(param_2 + 0x1b20) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    **(undefined4 **)(param_2 + 0x1b10) = *(undefined4 *)(param_2 + 0x1b20);
    *(longlong *)(param_2 + 0x1b28) = *(longlong *)(param_2 + 0x1d90) + 0x1b0;
    *(undefined8 *)(param_2 + 0x138) = **(undefined8 **)(param_2 + 0x1b28);
    FUN_180001c34(*(longlong **)(param_2 + 0x138));
  }
  return;
}


/* Function 180013de9 FUN_180013de9 */

void FUN_180013de9(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1b30) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
  *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 0x1b30);
  if ((*(uint *)(param_2 + 0x30) & 2) != 0) {
    *(longlong *)(param_2 + 0x1b38) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(longlong *)(param_2 + 0x1b40) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 0x1b40);
    *(uint *)(param_2 + 0x1b48) = *(uint *)(param_2 + 0x30) & 0xfffffffd;
    **(undefined4 **)(param_2 + 0x1b38) = *(undefined4 *)(param_2 + 0x1b48);
    *(longlong *)(param_2 + 0x1b50) = *(longlong *)(param_2 + 0x1d90) + 0x1b8;
    *(undefined8 *)(param_2 + 0x130) = **(undefined8 **)(param_2 + 0x1b50);
    FUN_180001c34(*(longlong **)(param_2 + 0x130));
  }
  return;
}


/* Function 180013e9e FUN_180013e9e */

void FUN_180013e9e(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 7000) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
  *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 7000);
  if ((*(uint *)(param_2 + 0x30) & 4) != 0) {
    *(longlong *)(param_2 + 0x1b60) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(longlong *)(param_2 + 0x1b68) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 0x1b68);
    *(uint *)(param_2 + 0x1b70) = *(uint *)(param_2 + 0x30) & 0xfffffffb;
    **(undefined4 **)(param_2 + 0x1b60) = *(undefined4 *)(param_2 + 0x1b70);
    *(longlong *)(param_2 + 0x1b78) = *(longlong *)(param_2 + 0x1d90) + 0x1c0;
    *(undefined8 *)(param_2 + 0x128) = **(undefined8 **)(param_2 + 0x1b78);
    FUN_180001c34(*(longlong **)(param_2 + 0x128));
  }
  return;
}


/* Function 180013f53 FUN_180013f53 */

void FUN_180013f53(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1b80) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
  *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 0x1b80);
  if ((*(uint *)(param_2 + 0x30) & 8) != 0) {
    *(longlong *)(param_2 + 0x1b88) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(longlong *)(param_2 + 0x1b90) = *(longlong *)(param_2 + 0x1d90) + 0x3c8;
    *(undefined4 *)(param_2 + 0x30) = **(undefined4 **)(param_2 + 0x1b90);
    *(uint *)(param_2 + 0x1b98) = *(uint *)(param_2 + 0x30) & 0xfffffff7;
    **(undefined4 **)(param_2 + 0x1b88) = *(undefined4 *)(param_2 + 0x1b98);
    *(longlong *)(param_2 + 0x1ba0) = *(longlong *)(param_2 + 0x1d90) + 0x1c8;
    *(undefined8 *)(param_2 + 0x120) = **(undefined8 **)(param_2 + 0x1ba0);
    FUN_180001c34(*(longlong **)(param_2 + 0x120));
  }
  return;
}


/* Function 180014008 FUN_180014008 */

void FUN_180014008(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1ba8) = *(longlong *)(param_2 + 0x1d90) + 0x1d0;
  *(undefined8 *)(param_2 + 0x7e8) = **(undefined8 **)(param_2 + 0x1ba8);
  _guard_check_icall();
  return;
}


/* Function 18001404c FUN_18001404c */

void FUN_18001404c(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *(longlong *)(param_2 + 0x1bb0) = *(longlong *)(param_2 + 0x1d90) + 0x1d8;
  uVar1 = **(undefined8 **)(param_2 + 0x1bb0);
  *(longlong *)(param_2 + 0x1bb8) = *(longlong *)(param_2 + 0x1d90) + 0x1d8;
  *(undefined8 *)(param_2 + 0x1bc0) = uVar1;
  **(undefined8 **)(param_2 + 0x1bb8) = *(undefined8 *)(param_2 + 0x1bc0);
  *(longlong *)(param_2 + 0x1bc8) = *(longlong *)(param_2 + 0x1d90) + 0x1d8;
  *(undefined8 *)(param_2 + 0x140) = **(undefined8 **)(param_2 + 0x1bc8);
  FUN_180001c34(*(longlong **)(param_2 + 0x140));
  return;
}


/* Function 1800140d3 FUN_1800140d3 */

void FUN_1800140d3(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1bd0) = *(longlong *)(param_2 + 0x1d90) + 0x210;
  *(undefined8 *)(param_2 + 0x158) = **(undefined8 **)(param_2 + 0x1bd0);
  FUN_180001c34(*(longlong **)(param_2 + 0x158));
  return;
}


/* Function 180014112 FUN_180014112 */

void FUN_180014112(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1bd8) = *(longlong *)(param_2 + 0x1d90) + 0x1f0;
  *(undefined8 *)(param_2 + 0x150) = **(undefined8 **)(param_2 + 0x1bd8);
  FUN_180001c34(*(longlong **)(param_2 + 0x150));
  return;
}


/* Function 180014151 FUN_180014151 */

void FUN_180014151(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1be0) = *(longlong *)(param_2 + 0x1d90) + 0x1e8;
  *(undefined8 *)(param_2 + 0x148) = **(undefined8 **)(param_2 + 0x1be0);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x148));
  return;
}


/* Function 180014190 FUN_180014190 */

void FUN_180014190(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1be8) = *(longlong *)(param_2 + 0x1d90) + 0x1e0;
  *(undefined8 *)(param_2 + 0x90) = **(undefined8 **)(param_2 + 0x1be8);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x90));
  return;
}


/* Function 1800141cf FUN_1800141cf */

void FUN_1800141cf(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1bf0) = *(longlong *)(param_2 + 0x1d90) + 0x218;
  *(undefined8 *)(param_2 + 0x9f0) = **(undefined8 **)(param_2 + 0x1bf0);
  _guard_check_icall();
  return;
}


/* Function 180014213 FUN_180014213 */

void FUN_180014213(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *(longlong *)(param_2 + 0x1bf8) = *(longlong *)(param_2 + 0x1d90) + 0x220;
  uVar1 = **(undefined8 **)(param_2 + 0x1bf8);
  *(longlong *)(param_2 + 0x1c00) = *(longlong *)(param_2 + 0x1d90) + 0x220;
  *(undefined8 *)(param_2 + 0x1c08) = uVar1;
  **(undefined8 **)(param_2 + 0x1c00) = *(undefined8 *)(param_2 + 0x1c08);
  *(longlong *)(param_2 + 0x1c10) = *(longlong *)(param_2 + 0x1d90) + 0x220;
  *(undefined8 *)(param_2 + 0x160) = **(undefined8 **)(param_2 + 0x1c10);
  FUN_180001c34(*(longlong **)(param_2 + 0x160));
  return;
}


/* Function 18001429a FUN_18001429a */

void FUN_18001429a(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c18) = *(longlong *)(param_2 + 0x1d90) + 0x240;
  *(undefined8 *)(param_2 + 0x178) = **(undefined8 **)(param_2 + 0x1c18);
  FUN_180001c34(*(longlong **)(param_2 + 0x178));
  return;
}


/* Function 1800142d9 FUN_1800142d9 */

void FUN_1800142d9(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c20) = *(longlong *)(param_2 + 0x1d90) + 0x238;
  *(undefined8 *)(param_2 + 0x170) = **(undefined8 **)(param_2 + 0x1c20);
  FUN_180001c34(*(longlong **)(param_2 + 0x170));
  return;
}


/* Function 180014318 FUN_180014318 */

void FUN_180014318(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c28) = *(longlong *)(param_2 + 0x1d90) + 0x230;
  *(undefined8 *)(param_2 + 0x168) = **(undefined8 **)(param_2 + 0x1c28);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x168));
  return;
}


/* Function 180014357 FUN_180014357 */

void FUN_180014357(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c30) = *(longlong *)(param_2 + 0x1d90) + 0x228;
  *(undefined8 *)(param_2 + 0x88) = **(undefined8 **)(param_2 + 0x1c30);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x88));
  return;
}


/* Function 180014396 FUN_180014396 */

void FUN_180014396(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c38) = *(longlong *)(param_2 + 0x1d90) + 0x248;
  *(undefined8 *)(param_2 + 0xbf8) = **(undefined8 **)(param_2 + 0x1c38);
  _guard_check_icall();
  return;
}


/* Function 1800143da FUN_1800143da */

void FUN_1800143da(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *(longlong *)(param_2 + 0x1c40) = *(longlong *)(param_2 + 0x1d90) + 0x250;
  uVar1 = **(undefined8 **)(param_2 + 0x1c40);
  *(longlong *)(param_2 + 0x1c48) = *(longlong *)(param_2 + 0x1d90) + 0x250;
  *(undefined8 *)(param_2 + 0x1c50) = uVar1;
  **(undefined8 **)(param_2 + 0x1c48) = *(undefined8 *)(param_2 + 0x1c50);
  *(longlong *)(param_2 + 0x1c58) = *(longlong *)(param_2 + 0x1d90) + 0x250;
  *(undefined8 *)(param_2 + 0x180) = **(undefined8 **)(param_2 + 0x1c58);
  FUN_180001c34(*(longlong **)(param_2 + 0x180));
  return;
}


/* Function 180014461 FUN_180014461 */

void FUN_180014461(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c60) = *(longlong *)(param_2 + 0x1d90) + 0x270;
  *(undefined8 *)(param_2 + 0x198) = **(undefined8 **)(param_2 + 0x1c60);
  FUN_180001c34(*(longlong **)(param_2 + 0x198));
  return;
}


/* Function 1800144a0 FUN_1800144a0 */

void FUN_1800144a0(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c68) = *(longlong *)(param_2 + 0x1d90) + 0x268;
  *(undefined8 *)(param_2 + 400) = **(undefined8 **)(param_2 + 0x1c68);
  FUN_180001c34(*(longlong **)(param_2 + 400));
  return;
}


/* Function 1800144df FUN_1800144df */

void FUN_1800144df(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c70) = *(longlong *)(param_2 + 0x1d90) + 0x260;
  *(undefined8 *)(param_2 + 0x188) = **(undefined8 **)(param_2 + 0x1c70);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x188));
  return;
}


/* Function 18001451e FUN_18001451e */

void FUN_18001451e(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c78) = *(longlong *)(param_2 + 0x1d90) + 600;
  *(undefined8 *)(param_2 + 0x80) = **(undefined8 **)(param_2 + 0x1c78);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x80));
  return;
}


/* Function 18001455d FUN_18001455d */

void FUN_18001455d(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1c80) = *(longlong *)(param_2 + 0x1d90) + 0x278;
  *(undefined8 *)(param_2 + 0xe00) = **(undefined8 **)(param_2 + 0x1c80);
  _guard_check_icall();
  return;
}


/* Function 1800145a1 FUN_1800145a1 */

void FUN_1800145a1(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *(longlong *)(param_2 + 0x1c88) = *(longlong *)(param_2 + 0x1d90) + 0x280;
  uVar1 = **(undefined8 **)(param_2 + 0x1c88);
  *(longlong *)(param_2 + 0x1c90) = *(longlong *)(param_2 + 0x1d90) + 0x280;
  *(undefined8 *)(param_2 + 0x1c98) = uVar1;
  **(undefined8 **)(param_2 + 0x1c90) = *(undefined8 *)(param_2 + 0x1c98);
  *(longlong *)(param_2 + 0x1ca0) = *(longlong *)(param_2 + 0x1d90) + 0x280;
  *(undefined8 *)(param_2 + 0x1a0) = **(undefined8 **)(param_2 + 0x1ca0);
  FUN_180001c34(*(longlong **)(param_2 + 0x1a0));
  return;
}


/* Function 180014628 FUN_180014628 */

void FUN_180014628(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1ca8) = *(longlong *)(param_2 + 0x1d90) + 0x2a0;
  *(undefined8 *)(param_2 + 0x1b8) = **(undefined8 **)(param_2 + 0x1ca8);
  FUN_180001c34(*(longlong **)(param_2 + 0x1b8));
  return;
}


/* Function 180014667 FUN_180014667 */

void FUN_180014667(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1cb0) = *(longlong *)(param_2 + 0x1d90) + 0x298;
  *(undefined8 *)(param_2 + 0x1b0) = **(undefined8 **)(param_2 + 0x1cb0);
  FUN_180001c34(*(longlong **)(param_2 + 0x1b0));
  return;
}


/* Function 1800146a6 FUN_1800146a6 */

void FUN_1800146a6(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1cb8) = *(longlong *)(param_2 + 0x1d90) + 0x290;
  *(undefined8 *)(param_2 + 0x1a8) = **(undefined8 **)(param_2 + 0x1cb8);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x1a8));
  return;
}


/* Function 1800146e5 FUN_1800146e5 */

void FUN_1800146e5(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1cc0) = *(longlong *)(param_2 + 0x1d90) + 0x288;
  *(undefined8 *)(param_2 + 0x78) = **(undefined8 **)(param_2 + 0x1cc0);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x78));
  return;
}


/* Function 18001471e FUN_18001471e */

void FUN_18001471e(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1cc8) = *(longlong *)(param_2 + 0x1d90) + 0x2a8;
  *(undefined8 *)(param_2 + 0x1008) = **(undefined8 **)(param_2 + 0x1cc8);
  _guard_check_icall();
  return;
}


/* Function 180014762 FUN_180014762 */

void FUN_180014762(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *(longlong *)(param_2 + 0x1cd0) = *(longlong *)(param_2 + 0x1d90) + 0x2b0;
  uVar1 = **(undefined8 **)(param_2 + 0x1cd0);
  *(longlong *)(param_2 + 0x1cd8) = *(longlong *)(param_2 + 0x1d90) + 0x2b0;
  *(undefined8 *)(param_2 + 0x1ce0) = uVar1;
  **(undefined8 **)(param_2 + 0x1cd8) = *(undefined8 *)(param_2 + 0x1ce0);
  *(longlong *)(param_2 + 0x1ce8) = *(longlong *)(param_2 + 0x1d90) + 0x2b0;
  *(undefined8 *)(param_2 + 0x1c0) = **(undefined8 **)(param_2 + 0x1ce8);
  FUN_180001c34(*(longlong **)(param_2 + 0x1c0));
  return;
}


/* Function 1800147e9 FUN_1800147e9 */

void FUN_1800147e9(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1cf0) = *(longlong *)(param_2 + 0x1d90) + 0x2b8;
  *(undefined8 *)(param_2 + 0x1a58) = **(undefined8 **)(param_2 + 0x1cf0);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x1a58));
  return;
}


/* Function 180014828 FUN_180014828 */

void FUN_180014828(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1cf8) = *(longlong *)(param_2 + 0x1d90) + 0x2c8;
  *(undefined8 *)(param_2 + 0x1c8) = **(undefined8 **)(param_2 + 0x1cf8);
  FUN_180001c34(*(longlong **)(param_2 + 0x1c8));
  return;
}


/* Function 180014867 FUN_180014867 */

void FUN_180014867(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d00) = *(longlong *)(param_2 + 0x1d90) + 0x2e0;
  *(undefined8 *)(param_2 + 0x1e0) = **(undefined8 **)(param_2 + 0x1d00);
  FUN_180001c34(*(longlong **)(param_2 + 0x1e0));
  return;
}


/* Function 1800148a6 FUN_1800148a6 */

void FUN_1800148a6(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d08) = *(longlong *)(param_2 + 0x1d90) + 0x2d8;
  *(undefined8 *)(param_2 + 0x1d8) = **(undefined8 **)(param_2 + 0x1d08);
  FUN_180001c34(*(longlong **)(param_2 + 0x1d8));
  return;
}


/* Function 1800148e5 FUN_1800148e5 */

void FUN_1800148e5(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d10) = *(longlong *)(param_2 + 0x1d90) + 0x2d0;
  *(undefined8 *)(param_2 + 0x1d0) = **(undefined8 **)(param_2 + 0x1d10);
  WindowsDeleteString(*(undefined8 *)(param_2 + 0x1d0));
  return;
}


/* Function 180014924 FUN_180014924 */

void FUN_180014924(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d18) = *(longlong *)(param_2 + 0x1d90) + 0x2e8;
  *(undefined8 *)(param_2 + 0x1f0) = **(undefined8 **)(param_2 + 0x1d18);
  FUN_180001c34(*(longlong **)(param_2 + 0x1f0));
  return;
}


/* Function 180014963 FUN_180014963 */

void FUN_180014963(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d20) = *(longlong *)(param_2 + 0x1d90) + 0x2f8;
  FUN_180001a44(*(longlong *)(param_2 + 0x1d20));
  return;
}


/* Function 180014991 FUN_180014991 */

void FUN_180014991(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d28) = *(longlong *)(param_2 + 0x1d90) + 0x2f0;
  *(undefined8 *)(param_2 + 0x1e8) = **(undefined8 **)(param_2 + 0x1d28);
  FUN_180001c34(*(longlong **)(param_2 + 0x1e8));
  return;
}


/* Function 1800149d0 FUN_1800149d0 */

undefined * FUN_1800149d0(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined8 uVar3;
  void *pvVar4;
  
  *(longlong *)(param_2 + 0x13a8) = *(longlong *)(param_2 + 0x1d90) + 0x900;
  uVar1 = FUN_180004874(*(longlong *)(param_2 + 0x218));
  *(undefined4 *)(param_2 + 0xc0) = uVar1;
  **(undefined4 **)(param_2 + 0x13a8) = *(undefined4 *)(param_2 + 0xc0);
  *(longlong *)(param_2 + 0x13b0) = *(longlong *)(param_2 + 0x1d90) + 0x900;
  *(undefined4 *)(param_2 + 0xf4) = **(undefined4 **)(param_2 + 0x13b0);
  if (*(int *)(param_2 + 0xf4) == -0x7ff8ffa9) {
    *(longlong *)(param_2 + 0x13b8) = *(longlong *)(param_2 + 0x1d90) + 0x910;
    puVar2 = FUN_180001e7c();
    *(undefined **)(param_2 + 0x13c0) = puVar2;
    **(undefined8 **)(param_2 + 0x13b8) = *(undefined8 *)(param_2 + 0x13c0);
    *(longlong *)(param_2 + 0x13c8) = *(longlong *)(param_2 + 0x1d90) + 0x910;
    *(undefined8 *)(param_2 + 0x13d0) = **(undefined8 **)(param_2 + 0x13c8);
    *(undefined8 *)(param_2 + 0x13d8) = *(undefined8 *)(param_2 + 0x13d0);
    FUN_180002518(*(longlong **)(param_2 + 0x13d8),
                  L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",
                  L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0xe8,
                  *(Message **)(param_2 + 0x218),L"Showing toast failed due to invalid argument");
    *(longlong *)(param_2 + 0x13e0) = *(longlong *)(param_2 + 0x1d90) + 0xd0;
    *(undefined8 *)(param_2 + 0x68) = **(undefined8 **)(param_2 + 0x13e0);
    *(longlong *)(param_2 + 0x13e8) = *(longlong *)(param_2 + 0x1d90) + 0x920;
    uVar3 = FUN_180001bb4('\0',*(undefined8 **)(param_2 + 0x68),&DAT_180016ae8);
    *(undefined8 *)(param_2 + 0x13f0) = uVar3;
    **(undefined8 **)(param_2 + 0x13e8) = *(undefined8 *)(param_2 + 0x13f0);
    *(longlong *)(param_2 + 0x1408) = *(longlong *)(param_2 + 0x1d90) + 0x318;
    *(longlong *)(param_2 + 0x13f8) = *(longlong *)(param_2 + 0x1d90) + 0x920;
    *(undefined8 *)(param_2 + 0x1400) = **(undefined8 **)(param_2 + 0x13f8);
    *(undefined8 *)(param_2 + 0x1410) = *(undefined8 *)(param_2 + 0x1400);
    **(undefined8 **)(param_2 + 0x1408) = *(undefined8 *)(param_2 + 0x1410);
    *(longlong *)(param_2 + 0x1418) = *(longlong *)(param_2 + 0x1d90) + 0x328;
    *(longlong *)(param_2 + 0x1420) = *(longlong *)(param_2 + 0x1d90) + 0x930;
    pvVar4 = FUN_180001a50(*(void **)(param_2 + 0x1418),L"InvalidParameter");
    *(void **)(param_2 + 0x1428) = pvVar4;
    **(undefined8 **)(param_2 + 0x1420) = *(undefined8 *)(param_2 + 0x1428);
    *(longlong *)(param_2 + 0x1430) = *(longlong *)(param_2 + 0x1d90) + 0x930;
    *(undefined8 *)(param_2 + 0x1438) = **(undefined8 **)(param_2 + 0x1430);
    *(undefined8 *)(param_2 + 0x1440) = *(undefined8 *)(param_2 + 0x1438);
    *(longlong *)(param_2 + 0x1448) = *(longlong *)(param_2 + 0x1d90) + 0x940;
    uVar3 = FUN_180001ac0(*(longlong *)(param_2 + 0x1440));
    *(undefined8 *)(param_2 + 0x1450) = uVar3;
    **(undefined8 **)(param_2 + 0x1448) = *(undefined8 *)(param_2 + 0x1450);
    *(longlong *)(param_2 + 0x1458) = *(longlong *)(param_2 + 0x1d90) + 0x940;
    *(undefined8 *)(param_2 + 0x1460) = **(undefined8 **)(param_2 + 0x1458);
    *(longlong *)(param_2 + 0x1468) = *(longlong *)(param_2 + 0x1d90) + 0x950;
    uVar3 = FUN_1800098a8(0,*(String **)(param_2 + 0x1460));
    *(undefined8 *)(param_2 + 0x1470) = uVar3;
    **(undefined8 **)(param_2 + 0x1468) = *(undefined8 *)(param_2 + 0x1470);
    *(longlong *)(param_2 + 0x1488) = *(longlong *)(param_2 + 0x1d90) + 800;
    *(longlong *)(param_2 + 0x1478) = *(longlong *)(param_2 + 0x1d90) + 0x950;
    *(undefined8 *)(param_2 + 0x1480) = **(undefined8 **)(param_2 + 0x1478);
    *(undefined8 *)(param_2 + 0x1490) = *(undefined8 *)(param_2 + 0x1480);
    **(undefined8 **)(param_2 + 0x1488) = *(undefined8 *)(param_2 + 0x1490);
    *(longlong *)(param_2 + 0x14a0) = *(longlong *)(param_2 + 0x1d90) + 0x3e0;
    *(longlong *)(param_2 + 0x1498) = *(longlong *)(param_2 + 0x1d90) + 800;
    *(undefined8 *)(param_2 + 0x1f8) = **(undefined8 **)(param_2 + 0x1498);
    *(undefined8 *)(param_2 + 0x14a8) = *(undefined8 *)(param_2 + 0x1f8);
    **(undefined8 **)(param_2 + 0x14a0) = *(undefined8 *)(param_2 + 0x14a8);
    *(longlong *)(param_2 + 0x14b0) = *(longlong *)(param_2 + 0x1d90) + 0xe8;
    *(longlong *)(param_2 + 0x14b8) = *(longlong *)(param_2 + 0x1d90) + 0x960;
    uVar3 = FUN_180001ac0(*(longlong *)(param_2 + 0x14b0));
    *(undefined8 *)(param_2 + 0x14c0) = uVar3;
    **(undefined8 **)(param_2 + 0x14b8) = *(undefined8 *)(param_2 + 0x14c0);
    *(longlong *)(param_2 + 0x14c8) = *(longlong *)(param_2 + 0x1d90) + 0x960;
    *(undefined8 *)(param_2 + 0x14d0) = **(undefined8 **)(param_2 + 0x14c8);
    *(undefined8 *)(param_2 + 0x14f0) = *(undefined8 *)(param_2 + 0x14d0);
    *(longlong *)(param_2 + 0x14d8) = *(longlong *)(param_2 + 0x1d90) + 0x3e0;
    *(undefined8 *)(param_2 + 0x14e8) = **(undefined8 **)(param_2 + 0x14d8);
    *(longlong *)(param_2 + 0x14e0) = *(longlong *)(param_2 + 0x1d90) + 0x318;
    *(undefined8 *)(param_2 + 0x200) = **(undefined8 **)(param_2 + 0x14e0);
    FUN_180001724(*(longlong **)(param_2 + 0x200));
    *(longlong *)(param_2 + 0x14f8) = *(longlong *)(param_2 + 0x1d90) + 800;
    *(undefined8 *)(param_2 + 0x1f8) = **(undefined8 **)(param_2 + 0x14f8);
    FUN_180001c34(*(longlong **)(param_2 + 0x1f8));
    *(longlong *)(param_2 + 0x1500) = *(longlong *)(param_2 + 0x1d90) + 0x328;
    FUN_180001a44(*(longlong *)(param_2 + 0x1500));
    *(longlong *)(param_2 + 0x1508) = *(longlong *)(param_2 + 0x1d90) + 0x318;
    *(undefined8 *)(param_2 + 0x200) = **(undefined8 **)(param_2 + 0x1508);
    FUN_180001c34(*(longlong **)(param_2 + 0x200));
  }
  else {
    *(longlong *)(param_2 + 0x1510) = *(longlong *)(param_2 + 0x1d90) + 0x970;
    puVar2 = FUN_180001e7c();
    *(undefined **)(param_2 + 0x1518) = puVar2;
    **(undefined8 **)(param_2 + 0x1510) = *(undefined8 *)(param_2 + 0x1518);
    *(longlong *)(param_2 + 0x1520) = *(longlong *)(param_2 + 0x1d90) + 0x970;
    *(undefined8 *)(param_2 + 0x1528) = **(undefined8 **)(param_2 + 0x1520);
    *(undefined8 *)(param_2 + 0x1530) = *(undefined8 *)(param_2 + 0x1528);
    FUN_180002518(*(longlong **)(param_2 + 0x1530),
                  L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",
                  L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0xed,
                  *(Message **)(param_2 + 0x218),L"Showing toast failed");
    *(longlong *)(param_2 + 0x1538) = *(longlong *)(param_2 + 0x1d90) + 0xd0;
    *(undefined8 *)(param_2 + 0x68) = **(undefined8 **)(param_2 + 0x1538);
    *(longlong *)(param_2 + 0x1540) = *(longlong *)(param_2 + 0x1d90) + 0x980;
    uVar3 = FUN_180001bb4('\0',*(undefined8 **)(param_2 + 0x68),&DAT_180016ae8);
    *(undefined8 *)(param_2 + 0x1548) = uVar3;
    **(undefined8 **)(param_2 + 0x1540) = *(undefined8 *)(param_2 + 0x1548);
    *(longlong *)(param_2 + 0x1560) = *(longlong *)(param_2 + 0x1d90) + 0x348;
    *(longlong *)(param_2 + 0x1550) = *(longlong *)(param_2 + 0x1d90) + 0x980;
    *(undefined8 *)(param_2 + 0x1558) = **(undefined8 **)(param_2 + 0x1550);
    *(undefined8 *)(param_2 + 0x1568) = *(undefined8 *)(param_2 + 0x1558);
    **(undefined8 **)(param_2 + 0x1560) = *(undefined8 *)(param_2 + 0x1568);
    *(longlong *)(param_2 + 0x1570) = *(longlong *)(param_2 + 0x1d90) + 0x358;
    *(longlong *)(param_2 + 0x1578) = *(longlong *)(param_2 + 0x1d90) + 0x990;
    pvVar4 = FUN_180001a50(*(void **)(param_2 + 0x1570),L"Failed");
    *(void **)(param_2 + 0x1580) = pvVar4;
    **(undefined8 **)(param_2 + 0x1578) = *(undefined8 *)(param_2 + 0x1580);
    *(longlong *)(param_2 + 0x1588) = *(longlong *)(param_2 + 0x1d90) + 0x990;
    *(undefined8 *)(param_2 + 0x1590) = **(undefined8 **)(param_2 + 0x1588);
    *(undefined8 *)(param_2 + 0x1598) = *(undefined8 *)(param_2 + 0x1590);
    *(longlong *)(param_2 + 0x15a0) = *(longlong *)(param_2 + 0x1d90) + 0x9a0;
    uVar3 = FUN_180001ac0(*(longlong *)(param_2 + 0x1598));
    *(undefined8 *)(param_2 + 0x15a8) = uVar3;
    **(undefined8 **)(param_2 + 0x15a0) = *(undefined8 *)(param_2 + 0x15a8);
    *(longlong *)(param_2 + 0x15b0) = *(longlong *)(param_2 + 0x1d90) + 0x9a0;
    *(undefined8 *)(param_2 + 0x15b8) = **(undefined8 **)(param_2 + 0x15b0);
    *(longlong *)(param_2 + 0x15c0) = *(longlong *)(param_2 + 0x1d90) + 0x9b0;
    uVar3 = FUN_1800098a8(0,*(String **)(param_2 + 0x15b8));
    *(undefined8 *)(param_2 + 0x15c8) = uVar3;
    **(undefined8 **)(param_2 + 0x15c0) = *(undefined8 *)(param_2 + 0x15c8);
    *(longlong *)(param_2 + 0x15e0) = *(longlong *)(param_2 + 0x1d90) + 0x350;
    *(longlong *)(param_2 + 0x15d0) = *(longlong *)(param_2 + 0x1d90) + 0x9b0;
    *(undefined8 *)(param_2 + 0x15d8) = **(undefined8 **)(param_2 + 0x15d0);
    *(undefined8 *)(param_2 + 0x15e8) = *(undefined8 *)(param_2 + 0x15d8);
    **(undefined8 **)(param_2 + 0x15e0) = *(undefined8 *)(param_2 + 0x15e8);
    *(longlong *)(param_2 + 0x15f8) = *(longlong *)(param_2 + 0x1d90) + 0x3f0;
    *(longlong *)(param_2 + 0x15f0) = *(longlong *)(param_2 + 0x1d90) + 0x350;
    *(undefined8 *)(param_2 + 0x208) = **(undefined8 **)(param_2 + 0x15f0);
    *(undefined8 *)(param_2 + 0x1600) = *(undefined8 *)(param_2 + 0x208);
    **(undefined8 **)(param_2 + 0x15f8) = *(undefined8 *)(param_2 + 0x1600);
    *(longlong *)(param_2 + 0x1608) = *(longlong *)(param_2 + 0x1d90) + 0xe8;
    *(longlong *)(param_2 + 0x1610) = *(longlong *)(param_2 + 0x1d90) + 0x9c0;
    uVar3 = FUN_180001ac0(*(longlong *)(param_2 + 0x1608));
    *(undefined8 *)(param_2 + 0x1618) = uVar3;
    **(undefined8 **)(param_2 + 0x1610) = *(undefined8 *)(param_2 + 0x1618);
    *(longlong *)(param_2 + 0x1620) = *(longlong *)(param_2 + 0x1d90) + 0x9c0;
    *(undefined8 *)(param_2 + 0x1628) = **(undefined8 **)(param_2 + 0x1620);
    *(undefined8 *)(param_2 + 0x1648) = *(undefined8 *)(param_2 + 0x1628);
    *(longlong *)(param_2 + 0x1630) = *(longlong *)(param_2 + 0x1d90) + 0x3f0;
    *(undefined8 *)(param_2 + 0x1640) = **(undefined8 **)(param_2 + 0x1630);
    *(longlong *)(param_2 + 0x1638) = *(longlong *)(param_2 + 0x1d90) + 0x348;
    *(undefined8 *)(param_2 + 0x210) = **(undefined8 **)(param_2 + 0x1638);
    FUN_180001724(*(longlong **)(param_2 + 0x210));
    *(longlong *)(param_2 + 0x1650) = *(longlong *)(param_2 + 0x1d90) + 0x350;
    *(undefined8 *)(param_2 + 0x208) = **(undefined8 **)(param_2 + 0x1650);
    FUN_180001c34(*(longlong **)(param_2 + 0x208));
    *(longlong *)(param_2 + 0x1658) = *(longlong *)(param_2 + 0x1d90) + 0x358;
    FUN_180001a44(*(longlong *)(param_2 + 0x1658));
    *(longlong *)(param_2 + 0x1660) = *(longlong *)(param_2 + 0x1d90) + 0x348;
    *(undefined8 *)(param_2 + 0x210) = **(undefined8 **)(param_2 + 0x1660);
    FUN_180001c34(*(longlong **)(param_2 + 0x210));
  }
  return &DAT_180011c6e;
}


/* Function 180015339 FUN_180015339 */

void FUN_180015339(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d30) = *(longlong *)(param_2 + 0x1d90) + 0x318;
  *(undefined8 *)(param_2 + 0x200) = **(undefined8 **)(param_2 + 0x1d30);
  FUN_180001c34(*(longlong **)(param_2 + 0x200));
  return;
}


/* Function 180015378 FUN_180015378 */

void FUN_180015378(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d38) = *(longlong *)(param_2 + 0x1d90) + 0x328;
  FUN_180001a44(*(longlong *)(param_2 + 0x1d38));
  return;
}


/* Function 1800153a6 FUN_1800153a6 */

void FUN_1800153a6(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d40) = *(longlong *)(param_2 + 0x1d90) + 800;
  *(undefined8 *)(param_2 + 0x1f8) = **(undefined8 **)(param_2 + 0x1d40);
  FUN_180001c34(*(longlong **)(param_2 + 0x1f8));
  return;
}


/* Function 1800153e5 FUN_1800153e5 */

void FUN_1800153e5(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d48) = *(longlong *)(param_2 + 0x1d90) + 0x348;
  *(undefined8 *)(param_2 + 0x210) = **(undefined8 **)(param_2 + 0x1d48);
  FUN_180001c34(*(longlong **)(param_2 + 0x210));
  return;
}


/* Function 180015424 FUN_180015424 */

void FUN_180015424(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d50) = *(longlong *)(param_2 + 0x1d90) + 0x358;
  FUN_180001a44(*(longlong *)(param_2 + 0x1d50));
  return;
}


/* Function 180015452 FUN_180015452 */

void FUN_180015452(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d58) = *(longlong *)(param_2 + 0x1d90) + 0x350;
  *(undefined8 *)(param_2 + 0x208) = **(undefined8 **)(param_2 + 0x1d58);
  FUN_180001c34(*(longlong **)(param_2 + 0x208));
  return;
}


/* Function 180015491 FUN_180015491 */

undefined * FUN_180015491(undefined8 param_1,longlong param_2)

{
  undefined *puVar1;
  
  *(longlong *)(param_2 + 0x1668) = *(longlong *)(param_2 + 0x1d90) + 0x9d0;
  puVar1 = FUN_180001e7c();
  *(undefined **)(param_2 + 0x1670) = puVar1;
  **(undefined8 **)(param_2 + 0x1668) = *(undefined8 *)(param_2 + 0x1670);
  *(longlong *)(param_2 + 0x1678) = *(longlong *)(param_2 + 0x1d90) + 0x9d0;
  *(undefined8 *)(param_2 + 0x1680) = **(undefined8 **)(param_2 + 0x1678);
  *(undefined8 *)(param_2 + 0x1688) = *(undefined8 *)(param_2 + 0x1680);
  FUN_1800031f0(*(longlong **)(param_2 + 0x1688),
                L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",
                L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0xf4,
                L"Showing toast failed");
  return &DAT_180011c6a;
}


/* Function 18001553b FUN_18001553b */

void FUN_18001553b(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d60) = *(longlong *)(param_2 + 0x1d90) + 0x388;
  *(undefined8 *)(param_2 + 0xa8) = **(undefined8 **)(param_2 + 0x1d60);
  FUN_180001c34(*(longlong **)(param_2 + 0xa8));
  return;
}


/* Function 18001557a FUN_18001557a */

void FUN_18001557a(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d68) = *(longlong *)(param_2 + 0x1d90) + 0x380;
  *(undefined8 *)(param_2 + 0x98) = **(undefined8 **)(param_2 + 0x1d68);
  FUN_180001c34(*(longlong **)(param_2 + 0x98));
  return;
}


/* Function 1800155b9 FUN_1800155b9 */

void FUN_1800155b9(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1d70) = *(longlong *)(param_2 + 0x1d90) + 0x390;
  FUN_180007a34(*(longlong **)(param_2 + 0x1d70));
  return;
}


/* Function 1800155e7 FUN_1800155e7 */

undefined * FUN_1800155e7(undefined8 param_1,longlong param_2)

{
  undefined *puVar1;
  
  *(longlong *)(param_2 + 0x1840) = *(longlong *)(param_2 + 0x1d90) + 0xa20;
  puVar1 = FUN_180001e7c();
  *(undefined **)(param_2 + 0x1848) = puVar1;
  **(undefined8 **)(param_2 + 0x1840) = *(undefined8 *)(param_2 + 0x1848);
  *(longlong *)(param_2 + 0x1850) = *(longlong *)(param_2 + 0x1d90) + 0xa20;
  *(undefined8 *)(param_2 + 0x1858) = **(undefined8 **)(param_2 + 0x1850);
  *(undefined8 *)(param_2 + 0x1860) = *(undefined8 *)(param_2 + 0x1858);
  FUN_180002518(*(longlong **)(param_2 + 0x1860),
                L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",
                L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0xfc,
                *(Message **)(param_2 + 0x1a40),L"Responding to toast display request failed");
  return &DAT_1800123fd;
}


/* Function 18001569d FUN_18001569d */

undefined * FUN_18001569d(undefined8 param_1,longlong param_2)

{
  undefined *puVar1;
  
  *(longlong *)(param_2 + 0x1868) = *(longlong *)(param_2 + 0x1d90) + 0xa30;
  puVar1 = FUN_180001e7c();
  *(undefined **)(param_2 + 0x1870) = puVar1;
  **(undefined8 **)(param_2 + 0x1868) = *(undefined8 *)(param_2 + 0x1870);
  *(longlong *)(param_2 + 0x1878) = *(longlong *)(param_2 + 0x1d90) + 0xa30;
  *(undefined8 *)(param_2 + 0x1880) = **(undefined8 **)(param_2 + 0x1878);
  *(undefined8 *)(param_2 + 0x1888) = *(undefined8 *)(param_2 + 0x1880);
  FUN_180002910(*(longlong **)(param_2 + 0x1888));
  return &DAT_1800123f9;
}


/* Function 180015753 FUN_180015753 */

undefined * FUN_180015753(undefined8 param_1,longlong param_2)

{
  undefined *puVar1;
  
  *(longlong *)(param_2 + 0x1890) = *(longlong *)(param_2 + 0x1d90) + 0xa40;
  puVar1 = FUN_180001e7c();
  *(undefined **)(param_2 + 0x1898) = puVar1;
  **(undefined8 **)(param_2 + 0x1890) = *(undefined8 *)(param_2 + 0x1898);
  *(longlong *)(param_2 + 0x18a0) = *(longlong *)(param_2 + 0x1d90) + 0xa40;
  *(undefined8 *)(param_2 + 0x18a8) = **(undefined8 **)(param_2 + 0x18a0);
  *(undefined8 *)(param_2 + 0x18b0) = *(undefined8 *)(param_2 + 0x18a8);
  FUN_180002e04(*(longlong **)(param_2 + 0x18b0));
  return &DAT_1800123f5;
}


/* Function 180015809 FUN_180015809 */

undefined * FUN_180015809(undefined8 param_1,longlong param_2)

{
  undefined *puVar1;
  
  *(longlong *)(param_2 + 0x18b8) = *(longlong *)(param_2 + 0x1d90) + 0xa50;
  puVar1 = FUN_180001e7c();
  *(undefined **)(param_2 + 0x18c0) = puVar1;
  **(undefined8 **)(param_2 + 0x18b8) = *(undefined8 *)(param_2 + 0x18c0);
  *(longlong *)(param_2 + 0x18c8) = *(longlong *)(param_2 + 0x1d90) + 0xa50;
  *(undefined8 *)(param_2 + 0x18d0) = **(undefined8 **)(param_2 + 0x18c8);
  *(undefined8 *)(param_2 + 0x18d8) = *(undefined8 *)(param_2 + 0x18d0);
  FUN_1800031f0(*(longlong **)(param_2 + 0x18d8),
                L"ScreenSketchAppService::ShowToastBackgroundTask::HandleRequestReceivedAsync",
                L"D:\\a\\1\\s\\src\\ScreenSketchAppService\\ShowToastBackgroundTask.cpp",0xfc,
                L"Responding to toast display request failed");
  return &DAT_1800123f1;
}


/* Function 1800158b3 FUN_1800158b3 */

undefined1 * FUN_1800158b3(undefined8 param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x1938) = *(longlong *)(param_2 + 0x1d90) + 8;
  *(undefined2 *)(param_2 + 0x70) = 0xffff;
  **(undefined2 **)(param_2 + 0x1938) = *(undefined2 *)(param_2 + 0x70);
  FUN_180007ef4((longlong *)(*(longlong *)(param_2 + 0x1d90) + -0x10));
  return &LAB_1800125c1;
}


/* Function 180015910 FUN_180015910 */

void FUN_180015910(void)

{
  FUN_180001e04((longlong *)&DAT_18001f618);
  return;
}


/* Function 180015920 FUN_180015920 */

void FUN_180015920(void)

{
  WindowsDeleteString(DAT_18001f650);
  return;
}


/* Function 180015930 FUN_180015930 */

void FUN_180015930(void)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = DAT_18001f668;
  if (DAT_18001f668 != 0) {
    LOCK();
    piVar1 = (int *)(DAT_18001f668 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      LOCK();
      piVar1 = (int *)(lVar3 + 0xc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar3);
      }
    }
  }
  return;
}


/* Function 180015990 FUN_180015990 */

void FUN_180015990(void)

{
  if (DAT_18001ef28 != '\0') {
    (*(code *)PTR__guard_dispatch_icall_1800165a8)(&DAT_18001ef18,0);
    DAT_18001ef28 = '\0';
  }
  return;
}


/* Function 1800159d0 ~_Fac_tidy_reg_t */

/* Library Function - Single Match
    public: __cdecl std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(void) __ptr64
   
   Library: Visual Studio 2019 Release */

void __thiscall std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(_Fac_tidy_reg_t *this)

{
  undefined8 *_Memory;
  longlong lVar1;
  
  while (_Memory = DAT_18001ef30, DAT_18001ef30 != (undefined8 *)0x0) {
    DAT_18001ef30 = (undefined8 *)*DAT_18001ef30;
    lVar1 = (*(code *)PTR__guard_dispatch_icall_1800165a8)();
    if (lVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_1800165a8)(lVar1,1);
    }
    free(_Memory);
  }
  return;
}

