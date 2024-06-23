def stop_wait():
    frame_size = int(input("Enter frame size : "))
    sent = 0
    while(sent<frame_size):
        print("Frame-" + str(sent) + " has been Transmitted.")
        ack = int(input("Enter Acknowledgement received : "))
        if(ack == sent):
            print("Ackowledgement received for Frame-" + str(sent))
            sent += 1
        else:
            print("Ackowledgement not received for Frame-" + str(sent))
    return

if __name__ == '__main__':
    stop_wait()