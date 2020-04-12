v 20130925 2
C 40000 40000 0 0 0 title-A1.sym
T 66100 40700 9 14 1 0 0 0 1
Freeflow sensor board - BMP280 version
T 70000 40100 9 10 1 0 0 0 1
Steve Glow
T 70000 40400 9 10 1 0 0 0 1
1
C 43100 50300 1 90 0 capacitor-1.sym
{
T 42400 50500 5 10 0 0 90 0 1
device=CAPACITOR
T 43300 51100 5 10 1 1 180 0 1
refdes=C2
T 42200 50500 5 10 0 0 90 0 1
symversion=0.1
T 43100 50300 5 10 0 0 90 0 1
footprint=sm_0603
T 43500 50600 5 10 1 1 180 0 1
value=0.1uF
}
C 42700 51200 1 0 0 3.3V-plus-1.sym
C 42800 50000 1 0 0 gnd-1.sym
C 50100 50300 1 90 0 capacitor-1.sym
{
T 49400 50500 5 10 0 0 90 0 1
device=CAPACITOR
T 49200 50500 5 10 0 0 90 0 1
symversion=0.1
T 50100 50300 5 10 0 0 90 0 1
footprint=sm_0603
T 50300 51100 5 10 1 1 180 0 1
refdes=C4
T 50500 50600 5 10 1 1 180 0 1
value=0.1uF
}
C 49700 51200 1 0 0 3.3V-plus-1.sym
C 49800 50000 1 0 0 gnd-1.sym
C 57100 50300 1 90 0 capacitor-1.sym
{
T 56400 50500 5 10 0 0 90 0 1
device=CAPACITOR
T 56200 50500 5 10 0 0 90 0 1
symversion=0.1
T 57100 50300 5 10 0 0 90 0 1
footprint=sm_0603
T 57300 51100 5 10 1 1 180 0 1
refdes=C6
T 57500 50600 5 10 1 1 180 0 1
value=0.1uF
}
C 56700 51200 1 0 0 3.3V-plus-1.sym
C 56800 50000 1 0 0 gnd-1.sym
C 43900 60500 1 0 0 mh.sym
{
T 43899 60500 5 10 0 1 0 0 1
footprint=mh
T 43900 61000 5 10 1 1 0 0 1
refdes=MH1
}
C 44800 60500 1 0 0 mh.sym
{
T 44799 60500 5 10 0 1 0 0 1
footprint=mh
T 44800 61000 5 10 1 1 0 0 1
refdes=MH2
}
T 44000 60100 9 10 1 0 0 0 1
Mounting holes
T 48900 55000 9 10 1 0 0 0 1
Connector to processor board
T 51300 49100 9 10 1 0 0 0 1
Pressure sensors
N 48300 56100 49600 56100 4
{
T 48400 56100 5 10 1 1 0 0 1
netname=I2C_SCL
}
N 50500 56900 51800 56900 4
{
T 50600 56900 5 10 1 1 0 0 1
netname=I2C_SDA
}
N 48300 56300 49600 56300 4
{
T 48400 56300 5 10 1 1 0 0 1
netname=SPI_MISO
}
N 50500 57100 51800 57100 4
{
T 50600 57100 5 10 1 1 0 0 1
netname=SPI_MOSI
}
N 50500 56700 51800 56700 4
{
T 50600 56700 5 10 1 1 0 0 1
netname=SPI_SCLK
}
N 51800 56100 50500 56100 4
{
T 50600 56100 5 10 1 1 0 0 1
netname=SWDIO
}
N 51800 56300 50500 56300 4
{
T 50600 56300 5 10 1 1 0 0 1
netname=SWCLK
}
N 48300 57300 49600 57300 4
{
T 48400 57300 5 10 1 1 0 0 1
netname=SPI_SS1
}
N 49600 57100 48300 57100 4
{
T 48400 57100 5 10 1 1 0 0 1
netname=SPI_SS2
}
N 46400 56900 49600 56900 4
{
T 48400 56900 5 10 1 1 0 0 1
netname=BOARD_ID
}
C 49300 57800 1 0 0 3.3V-plus-1.sym
C 49500 55400 1 0 0 gnd-1.sym
C 50400 55400 1 0 0 gnd-1.sym
N 51800 57300 50500 57300 4
{
T 50600 57300 5 10 1 1 0 0 1
netname=SPI_SS3
}
N 49500 57800 49500 57500 4
N 49500 57500 49600 57500 4
C 49600 55500 1 0 0 header2x10.sym
{
T 48200 57700 5 10 0 0 0 0 1
footprint=header2x10s
T 50000 57800 5 10 1 1 0 0 1
refdes=J3
}
C 50500 57800 1 0 0 3.3V-plus-1.sym
N 50500 57500 50700 57500 4
N 50700 57500 50700 57800 4
C 46500 55900 1 90 0 resistor-1.sym
{
T 46100 56200 5 10 0 0 90 0 1
device=RESISTOR
T 46200 56600 5 10 1 1 180 0 1
refdes=R1
T 46500 55900 5 10 0 0 90 0 1
footprint=sm_0603
T 45900 56200 5 10 1 1 0 0 1
value=10k
}
N 46400 56900 46400 56800 4
C 46300 55600 1 0 0 gnd-1.sym
C 48300 56000 1 90 0 testpt-1.sym
{
T 47900 56200 5 10 1 1 180 0 1
refdes=TP2
T 47400 56400 5 10 0 0 90 0 1
device=TESTPOINT
T 47600 56400 5 10 0 0 90 0 1
footprint=testpoint
}
C 51800 56200 1 270 0 testpt-1.sym
{
T 52200 56000 5 10 1 1 0 0 1
refdes=TP4
T 52700 55800 5 10 0 0 270 0 1
device=TESTPOINT
T 52500 55800 5 10 0 0 270 0 1
footprint=testpoint
}
C 51800 56400 1 270 0 testpt-1.sym
{
T 52200 56200 5 10 1 1 0 0 1
refdes=TP5
T 52700 56000 5 10 0 0 270 0 1
device=TESTPOINT
T 52500 56000 5 10 0 0 270 0 1
footprint=testpoint
}
C 51800 57000 1 270 0 testpt-1.sym
{
T 52200 56800 5 10 1 1 0 0 1
refdes=TP6
T 52700 56600 5 10 0 0 270 0 1
device=TESTPOINT
T 52500 56600 5 10 0 0 270 0 1
footprint=testpoint
}
C 47700 60500 1 0 0 mh.sym
{
T 47699 60500 5 10 0 1 0 0 1
footprint=spacer
T 47700 61000 5 10 1 1 0 0 1
refdes=MH3
}
C 48600 60500 1 0 0 mh.sym
{
T 48599 60500 5 10 0 1 0 0 1
footprint=spacer
T 48600 61000 5 10 1 1 0 0 1
refdes=MH4
}
T 47700 60000 9 10 1 0 0 0 2
Board spacers,
for mounting processor board
C 55000 55800 1 270 0 testpt-1.sym
{
T 55400 55600 5 10 1 1 0 0 1
refdes=TP7
T 55900 55400 5 10 0 0 270 0 1
device=TESTPOINT
T 55700 55400 5 10 0 0 270 0 1
footprint=testpoint
}
C 54900 55400 1 0 0 gnd-1.sym
C 55000 56200 1 270 0 testpt-1.sym
{
T 55400 56000 5 10 1 1 0 0 1
refdes=TP8
T 55900 55800 5 10 0 0 270 0 1
device=TESTPOINT
T 55700 55800 5 10 0 0 270 0 1
footprint=testpoint
}
C 54800 56100 1 0 0 3.3V-plus-1.sym
C 44000 49800 1 0 0 BMP280.sym
{
T 44100 51300 5 10 1 1 0 0 1
device=BMP280
T 44200 50500 5 10 1 1 0 0 1
refdes=U1
T 43400 51500 5 10 0 0 0 0 1
footprint=BMP280
}
C 44300 53100 1 0 0 3.3V-plus-1.sym
N 44500 53100 44500 52300 4
N 45100 52300 45100 52700 4
N 45100 52700 44500 52700 4
C 44400 49500 1 0 0 gnd-1.sym
C 45000 49500 1 0 0 gnd-1.sym
N 45900 50900 46900 50900 4
{
T 45900 50900 5 10 1 1 0 0 1
netname=SPI_SCLK
}
N 45900 50700 46900 50700 4
{
T 45900 50700 5 10 1 1 0 0 1
netname=SPI_MISO
}
N 45900 51100 46900 51100 4
{
T 45900 51100 5 10 1 1 0 0 1
netname=SPI_MOSI
}
N 45900 51300 46900 51300 4
{
T 45900 51300 5 10 1 1 0 0 1
netname=SPI_SS1
}
C 51000 49800 1 0 0 BMP280.sym
{
T 50400 51500 5 10 0 0 0 0 1
footprint=BMP280
T 51100 51300 5 10 1 1 0 0 1
device=BMP280
T 51200 50500 5 10 1 1 0 0 1
refdes=U2
}
C 51300 53100 1 0 0 3.3V-plus-1.sym
N 51500 53100 51500 52300 4
N 52100 52300 52100 52700 4
N 52100 52700 51500 52700 4
C 51400 49500 1 0 0 gnd-1.sym
C 52000 49500 1 0 0 gnd-1.sym
N 52900 50900 53900 50900 4
{
T 52900 50900 5 10 1 1 0 0 1
netname=SPI_SCLK
}
N 52900 50700 53900 50700 4
{
T 52900 50700 5 10 1 1 0 0 1
netname=SPI_MISO
}
N 52900 51100 53900 51100 4
{
T 52900 51100 5 10 1 1 0 0 1
netname=SPI_MOSI
}
N 52900 51300 53900 51300 4
{
T 52900 51300 5 10 1 1 0 0 1
netname=SPI_SS2
}
C 58000 49800 1 0 0 BMP280.sym
{
T 57400 51500 5 10 0 0 0 0 1
footprint=BMP280
T 58100 51300 5 10 1 1 0 0 1
device=BMP280
T 58200 50500 5 10 1 1 0 0 1
refdes=U3
}
C 58300 53100 1 0 0 3.3V-plus-1.sym
N 58500 53100 58500 52300 4
N 59100 52300 59100 52700 4
N 59100 52700 58500 52700 4
C 58400 49500 1 0 0 gnd-1.sym
C 59000 49500 1 0 0 gnd-1.sym
N 59900 50900 60900 50900 4
{
T 59900 50900 5 10 1 1 0 0 1
netname=SPI_SCLK
}
N 59900 50700 60900 50700 4
{
T 59900 50700 5 10 1 1 0 0 1
netname=SPI_MISO
}
N 59900 51100 60900 51100 4
{
T 59900 51100 5 10 1 1 0 0 1
netname=SPI_MOSI
}
N 59900 51300 60900 51300 4
{
T 59900 51300 5 10 1 1 0 0 1
netname=SPI_SS3
}
