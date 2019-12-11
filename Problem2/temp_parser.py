#!/usr/bin/env python
import sys

def read_file():
    readfile = open(sys.argv[1], "r")

    global temps;
    temps = []

    for line in readfile:
        if len(line) > 3:
            continue
        else:
            temps.append(line);

    readfile.close()

def parse_temps():
    des_temp = int(sys.argv[2]);
    des_temp_found = 0

    for i in range(len(temps)):
        temps[i] = int(temps[i])
        if temps[i] < des_temp:
            des_temp_found += 1

    avg_temp = sum(temps) / len(temps)

    print("\nFile name of sensor temperatures: %s" % sys.argv[1])
    print("The number of temperatures found below %s degrees C: %s" % (des_temp, des_temp_found))
    print("The average temperature is: %s\n" % avg_temp)

if __name__ == "__main__":
    read_file()
    parse_temps()
