file1 = open('pixel_data.txt', 'r')
count = 0
 
# Using for loop
print("Using for loop")
for line in file1:
    count += 1
    print("Line{}: {}".format(count, line.strip()))
 
# Closing files
file1.close()