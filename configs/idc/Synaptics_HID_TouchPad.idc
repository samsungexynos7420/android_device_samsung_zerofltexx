# Input Device Configuration File for the Atmel Maxtouch touch screen.

# Internal Device Flag
device.internal = 0

# Touch Parameters
touch.deviceType = pointer
touch.orientationAware = 1
touch.gestureMode = pointer

# Touch Size Calibration
# Calibration for touch size is based on pressure.
touch.touchSize.calibration = pressure

# Tool Size Calibration
# Calibration for tool size is based on area measurement.
# The size of the tool is estimated using empirical measurements.
touch.toolSize.calibration = area
touch.toolSize.areaScale = 22
touch.toolSize.areaBias = 0
touch.toolSize.linearScale = 6
touch.toolSize.linearBias = 0
touch.toolSize.isSummed = 0

# Pressure Calibration
# Calibration for touch pressure is based on amplitude.
touch.pressure.calibration = amplitude
touch.pressure.source = default
touch.pressure.scale = 0.0125

# Size Calibration
# Calibration for touch size is normalized.
touch.size.calibration = normalized

# Orientation Calibration
# Calibration for touch orientation is vector.
touch.orientation.calibration = vector
