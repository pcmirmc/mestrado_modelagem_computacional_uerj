
from GreateCircle import GreatCircle


def main():

    """
    Creates two lists of dictionaries for start and destination city names and locations.
    Iterates list, setting GreatCircle object attributes,
    then calculating and printing full details.
    """

    print("-------------------------")
    print("| codedrome.com         |")
    print("| Great Circle Distance |")
    print("-------------------------\n")

    location1 = ("add1", -22.2836889, -42.5377769)
    location2 = ("add2", -22.2916383, -42.5362683)



    gc = GreatCircle(location1,location2)

    gc.calculate()

    output(gc)


def output(gc):

    """
    Prints out all details in a neatly annotated format.
    """

    if gc.valid == True:

        print("Name 1: " + gc.name1)
        print("Latitude %f degrees / %f radians" % (gc.latitude1_degrees, gc.latitude1_radians))
        print("Longitude %f degrees /  %f radians" % (gc.longitude1_degrees, gc.longitude1_radians))

        print("Name 2: " + gc.name2)
        print("Latitude %f degrees / %f radians" % (gc.latitude2_degrees, gc.latitude2_radians))
        print("Longitude %f degrees /  %f radians" % (gc.longitude2_degrees, gc.longitude2_radians))

        print("Valid: " + str(gc.valid))
        print("Central angle %f radians / %f degrees" % (gc.central_angle_radians, gc.central_angle_degrees))
        print("Distance %f kilometers / %f miles" % (gc.distance_kilometres, gc.distance_miles))

    else:

        print("Latitude and/or longitude for %s and %s are invalid" % (gc.name1, gc.name2))

    print("")


main()