### v3.1.0+1 — current trusted firmware

> This is the current firmware release. The device should accept it only after the configured image-authentication and 
> anti-rollback checks pass. If an update fails its runtime self-tests, the device should revert to a known-good image 
> where supported. If normal boot and recovery are both unavailable, the device should enter a defined recovery state 
> rather than silently accepting an older vulnerable image.