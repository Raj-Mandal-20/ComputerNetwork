# Selective Repeat
import random
frameSize = int(input("Enter no of frames: "))
windows = int(input("Enter the window size: "))
count = 0
temp = []
frames = list(map(int, input(f"Enter {frameSize} frames : ").strip().split()))[:frameSize]
for i in range(frameSize):
    flag = random.randint(1, 10) % 2
    if flag == 0:
        print(f"Frame {i + 1} with value {frames[i]} is acknowledged!")
        count += 1
    else:
        print(f"Frame {i + 1} with value {frames[i]} is not acknowledged!")
        count += 1
        temp.append(frames[i])
    if (i + 1) % windows == 0:
        while len(temp) != 0:
            frame = temp.pop(0)
            print(f"Frame {i+1} with value {frame} is retransmitted!")
            count += 1
            print(f"Frame {i+1} with value {frame} is acknowledged in second attempt!")
while len(temp) != 0:
    frame = temp.pop(0)
    print(f"Frame with value {frame} is retransmitted!")
    count += 1
    print(f"Frame with value {frame} is acknowledged in second attempt!")
print(f"Total no of transmissions is {count}!")    