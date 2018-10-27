# Organizing lists


# .sort changes list permanently; puts in alpha order
cars = ['bmw', 'audi', 'toyota', 'subaru'] 
cars.sort() #the list will never revert back to the original order
print(cars)

cars.sort(reverse=True)
print(cars)

cars.sort(reverse=False)
print(cars)


# .sorted() changes a list temporarily 
# let's you display it in one order without changing actual order
# harder to do this with capital letters

leds = ['smd', "3mm", '5mm', '10mm', 'rgb']
print("Here is the OG list: ")
print(leds)

print("\nHere is the sorted list: ")
print(sorted(leds))
#puts 10mm before 3mm and 5mm?

print("\nHere is the OG list: ")
print(leds)

print("\nHere is the sorted list again:")
#leds.sorted(reverse=False)
print(sorted(leds, reverse=False))


# .reverse sorts in reverse - not alpha reverse, but reverse order of list
print(leds)
leds.reverse()
print(leds)


# len() to find the length of a list
print(len(leds))

print("\n\nEXERCISES 3.8")


############## EXERCISES 3

#3.8
destinations = ['japan', 'brazil', 'uk', 'morocco', 'estonia']
print(destinations)

print("\n")
print(sorted(destinations))
print(destinations)

print("\n")
print(sorted(destinations, reverse=True))
print(destinations)

print('\n')
destinations.reverse()
print(destinations)
destinations.reverse()
print(destinations)

print("\n")
destinations.sort()
print(destinations)
destinations.sort(reverse=True)
print(destinations)

#3.9
#see motorcycles.py


print("\n\nEXERCISES 3.10")

#3.10
# value.append(value) - don't print this! X
# value.insert(position, value) X
# del name[position] X
# value.pop() X
# value.remove(value) X
# value.sort() X
# sorted(value) X - have to print this or store in variable since passing list as argument
# value.reverse X
# len(value) X

boroughs = ['manhattan', 'bronx', 'queens', 'staten island', 'brooklyn']
print(boroughs)
del boroughs[-2]
print(boroughs)

boroughs.append('staten island')
print(boroughs)

not_lived = boroughs.pop(1)
print("One borough I have not lived in is the " + not_lived.title())
print(boroughs)

boroughs.remove('staten island')
boroughs.remove('queens')
print(boroughs)

print("I have lived in " + boroughs[0].title() + " and " + boroughs[1].title())

boroughs.insert(0, 'staten island')
boroughs.insert(3, 'queens')
boroughs.insert(4, 'bronx')
print(boroughs)

print(len(boroughs))

print(sorted(boroughs))
print(sorted(boroughs, reverse=True))

boroughs.sort() #can't sort this in a variable
print(boroughs)

boroughs.reverse()
print(boroughs)

sort = sorted(boroughs)
print(sort)













