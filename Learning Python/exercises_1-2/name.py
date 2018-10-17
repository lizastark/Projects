#name = "ada lovelace"
#print(name.title())
#print(name.upper())
#print(name.lower())

#name1 = name.title()
#print(name1)

first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name

print(full_name)
print(full_name.title())

print("Well hello, " + full_name.title() + "!")

message = "Hello there " + full_name.upper()
print(message)

print("\tada" + "\t\tlovelace")

print("Characters: \n\tAda \n\t\tCharles \n\t\t\tShelley")

fav_lang = " python "
print(fav_lang + "kitties")

print(fav_lang.rstrip() + "kitties")

fav_lang = fav_lang.rstrip()
print(fav_lang + "puppies")

print("puppies" + fav_lang.lstrip())

print("puppies" + fav_lang.strip() + "kitties")