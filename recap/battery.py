from subprocess import Popen,PIPE

process=Popen(['upower','-i','/org/freedesktop/UPower/devices/battery_BAT0'],stdout=PIPE)
process1=Popen(['grep','-E','state|to\ full|percentage'],stdin=process.stdout,stdout=PIPE)

print process1.stdout.read().split('\n')
