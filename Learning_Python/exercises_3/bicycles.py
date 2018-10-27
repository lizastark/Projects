bicycles = ['trek','cannondale','redline','specialized']
print(bicycles)
print(bicycles[0])
print(bicycles[0].title())
print(bicycles[1].upper())
print(bicycles[2].lower())
print(bicycles[-1].upper()) #last line uses -1 so you don't have to know how long the list is

message = "My first bicycle was a " + bicycles[0].title() + "."
print(message)


#3.1 Names
names = ['caitlin', 'lara', 'nick']
print(names)
print(names[0].title())
print(names[1].lower())
print(names[-1].upper())

#3.2 Greetings
caitlinMessage = "Thank you SO MUCH " + names[0].title() + " for organizing NYE!"
laraMessage = "How's the carpet making coming " + names[1].upper() + "? I can't wait to see!"
nickMessage = "Hey " + names[-1].lower() + ", what's your fav AR project?"

print(caitlinMessage)
print(laraMessage)
print(nickMessage)

#3.3 Your Own List
tools = ['needle', 'soldering iron', 'needlenose pliers', 'sewing machine', 'vinyl cutter']
favTools = "My fav tools are my " + tools[0] + ", " + tools[1] + ", " + tools[2] + ", " + tools[3] + ", and " + tools[-1]
everydayTools = "My everyday tools are my " + tools[2].upper() + " and " + tools[0].upper()
solderingTools = "I use my " + tools[1] + " and my " + tools[2] + " to solder."
sewingTools = tools[0].title() + " and " + tools[-2].lower() + " are my go-tos for sewing."

print(favTools)
print(everydayTools)
print(solderingTools)
print(sewingTools)