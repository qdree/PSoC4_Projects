# THIS FILE IS AUTOMATICALLY GENERATED
# Project: E:\744\Education\Git\PSoC4_Projects\Diploma_sketch\pir_sensor.cydsn\pir_sensor.cyprj
# Date: Tue, 26 Apr 2016 11:31:46 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]


# Component constraints for E:\744\Education\Git\PSoC4_Projects\Diploma_sketch\pir_sensor.cydsn\TopDesign\TopDesign.cysch
# Project: E:\744\Education\Git\PSoC4_Projects\Diploma_sketch\pir_sensor.cydsn\pir_sensor.cyprj
# Date: Tue, 26 Apr 2016 11:31:45 GMT
