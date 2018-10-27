motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

#motorcycles[0] = 'ducati'
#print(motorcycles)


#appending to the lists
motorcycles.append('ducati')
print(motorcycles)

tools = []
tools.append('alligator clips')
tools.append('embroidery hoop')
tools.append('snips')

print(tools)

#deleting from the list
del tools[0]
print(tools)

del tools[0]
print(tools)

tools.append('embroidery hoop')
tools.append('alligator clips')

print(tools)


#pop() - removes last item in a list but can still work with it
print("\n" + "Let the popping begin")
popped_tool = tools.pop() #takes off alligator clips because it is in the last position
print(tools)
print(popped_tool)

last_used = tools.pop()
print("The last tool I used was an " + last_used.title() + ".")
print(tools) #see what tools we have in the list at the moment

tools.append('embroidery hoop')
tools.append('alligator clips')
print(tools)

first_used = tools.pop(0)
print("The first tool I used today was " + first_used)

second_used = tools.pop(0)
print("The first tool I used today was " + first_used)
print("The second tool I used today was " + second_used)

print(tools)

tools.append('measuring tape')
tools.append('power supply')
tools.append('multimeter')

print(tools)

tools.remove('power supply')
print(tools)

needs_batteries = 'multimeter'
tools.remove(needs_batteries)
print(tools)
print("My " + needs_batteries.upper() + " ran out of power.")




############## EXERCISES 3

#3.4
guests = ['anni albers', 'donna haraway', 'ada lovelace']
print("\nDear " + guests[0].title() + ", could you weave us into your dinner plans?")
print("Dear " + guests[1].title() + ", let's talk about cyborgs!")
print("Dear " + guests[-1].title() + ", I have this new machine you should check out over dinner.")


#3.5
not_attending = guests.pop(0)
now_attending = "fiona raby"
print("I'm so sorry to hear you can't join us " + not_attending.title() + ", but " + now_attending.title() + " can attend in your place.")

guests.append('fiona raby')
print("This brings our list to " + guests[0].title() + ", " + guests[1].title() + ", and " + guests[-1].title() + ". But we have found a bigger table so we can invite more ppl!")


#3.6
guests.insert(0, 'james baldwin')
guests.insert(2, 'ursala la guin')
guests.append('octavia butler')
print(guests)

print("Dear " + guests[0].title() + ", won't you please join us for dinner?")
print("Dear " + guests[1].title() + ", won't you please join us for dinner?")
print("Dear " + guests[2].title() + ", won't you please join us for dinner?")
print("Dear " + guests[3].title() + ", won't you please join us for dinner?")
print("Dear " + guests[-1].title() + ", won't you please join us for dinner?")

#3.7
numberOfGuests = "2"
print("Hello everyone, unfortunately we can now only have " + numberOfGuests + " for dinner.")

dropped = guests.pop(0)
print("Sorry, " + dropped.title() + ", you're uninvited.")

dropped = guests.pop(0)
print("Sorry, " + dropped.title() + ", you're uninvited.")

dropped = guests.pop(0)
print("Sorry, " + dropped.title() + ", you're uninvited.")

dropped = guests.pop(0)
print("Sorry, " + dropped.title() + ", you're uninvited")

print("Dear " + guests[0].title() + " and " + guests[1].title() + ", you're still invited!")

print(guests)

del guests[0]
print(guests)

#octavia moves from the 1 position to 0 after deleting fiona
del guests[0]
print(guests)

print(len(guests))






















