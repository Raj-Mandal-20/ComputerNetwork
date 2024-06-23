def sliding_window(window_size, frame_size):
    frames = list(map(int, input("Enter "+str(frame_size)+" frames : ").strip().split()))[:frame_size]
    print(type(frames))
    for i in range (frame_size):
        if((i+1)%window_size == 0):
            print(frames[i], end=" ")
            print("\nAcknowledgement of above frames is received.")
        else:
            print(frames[i],end =" ")
    if(frame_size%window_size != 0):
        print("\nAcknowledgement of above frames is received.")
    return

if __name__ == '__main__':
    window_size = int(input("Enter window size : "))
    frame_size = int(input("Enter frame size : "))
    sliding_window(window_size, frame_size)

