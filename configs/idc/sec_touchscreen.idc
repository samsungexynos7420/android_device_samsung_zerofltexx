# Input Device Configuration File for the Atmel Maxtouch touch screen.
# These calibration values are derived from empirical measurements
# and may not be appropriate for use with other touch screens.
# Refer to the input device configuration documentation for more details.

# Basic Parameters
touch.deviceType = touchScreen
touch.orientationAware = 1

# Touch Size
touch.touchSize.calibration = pressure

# Tool Size
# The driver reports the tool size as an area measurement.
# We estimate the size of the tool based on empirical measurements.
touch.toolSize.calibration = area
touch.toolSize.areaScale = 22
touch.toolSize.areaBias = 0
touch.toolSize.linearScale = 6
touch.toolSize.linearBias = 0
touch.toolSize.isSummed = 0

# Pressure
# The driver reports signal strength as pressure.
# A normal index finger touch typically registers about 80 signal strength units.
touch.pressure.calibration = amplitude
touch.pressure.source = default
touch.pressure.scale = 0.0125

# Size
# Calibration for touch size is normalized.
touch.size.calibration = normalized

# Orientation
# Calibration for touch orientation is vector.
touch.orientation.calibration = vector
