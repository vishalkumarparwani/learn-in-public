import threading
import time

def task(name):
    print(f"Thread {name}: stared")
    time.sleep(1)
    print(f"Thread {name}: finished")

t1 = threading.Thred(target=task, args=("A",))
t2 = threading.Thread(target=task, args=("B",))

t1.start()
t2.start()

t1.join()
t2.join()
