#pragma once

enum HIP_DEVICE_TYPE
{
	NVIDIA,
	AMD,
	NONE
};

HIP_DEVICE_TYPE get_hip_device_type();