#if (YY_Thunks_Target < __WindowsNT6_2)
#include <dcomp.h>
#endif

namespace YY::Thunks {
#if (YY_Thunks_Target < __WindowsNT6_2)

// Minimum supported client	Windows 8 [desktop apps only]
// Minimum supported server Windows Server 2012 [desktop apps only]
__DEFINE_THUNK(dcomp,
               12,
               HRESULT,
               STDAPICALLTYPE,
               DCompositionCreateDevice,
               _In_opt_ IDXGIDevice* dxgiDevice,
               _In_ REFIID iid,
               _Outptr_ void** dcompositionDevice) {
  if (const auto _pfnDCompositionCreateDevice =
          try_get_DCompositionCreateDevice()) {
    return _pfnDCompositionCreateDevice(dxgiDevice, iid, dcompositionDevice);
  }

  if (!dcompositionDevice)
    return E_POINTER;

  *dcompositionDevice = nullptr;
  return E_NOTIMPL;
}
#endif
}  // namespace YY::Thunks
