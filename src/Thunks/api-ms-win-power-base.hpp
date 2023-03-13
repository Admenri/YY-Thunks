#if (YY_Thunks_Support_Version < NTDDI_WIN8)
#include <powrprof.h>
#endif

#if (YY_Thunks_Support_Version < NTDDI_WIN8)
#pragma comment(lib, "PowrProf.lib")
#endif

namespace YY
{
	namespace Thunks
	{
#if (YY_Thunks_Support_Version < NTDDI_WIN8)

		// �����֧�ֵĿͻ���	Windows 8 [����Ӧ��|UWP Ӧ��]
		// �����֧�ֵķ�����	Windows Server 2012[����Ӧ�� | UWP Ӧ��]
		__DEFINE_THUNK(
		powrprof,
		4,
		POWER_PLATFORM_ROLE,
		WINAPI,
		PowerDeterminePlatformRoleEx,
			_In_ ULONG _uVersion
			)
		{
			if (auto const _pfnPowerDeterminePlatformRoleEx = try_get_PowerDeterminePlatformRoleEx())
			{
				return _pfnPowerDeterminePlatformRoleEx(_uVersion);
			}

			if (_uVersion == POWER_PLATFORM_ROLE_V1)
			{
				return PowerDeterminePlatformRole();
			}
			else
			{
				return PlatformRoleUnspecified;
			}
		}
#endif
	}
}
