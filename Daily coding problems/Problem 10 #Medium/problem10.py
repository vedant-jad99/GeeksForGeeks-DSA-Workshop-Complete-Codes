from time import sleep, time
import threading

class Scheduler:
    def __init__(self):
        self.fns = []
        self.lock = threading.RLock()
        self.condition = threading.Condition(self.lock)
        self.thread = threading.Thread(target=self.schedule)
        self.thread.start()
    
    def schedule(self):
        while True:
            now = time() * 1000

            with self.lock:
                to_run = [fn for fn, due in self.fns if due <= now]
                self.fns = [(fn, due) for (fn, due) in self.fns if due > now]

            for fn in to_run:
                fn()

            with self.lock:
                if not self.fns:
                    self.condition.wait()
                else:
                    ms_remaining = min(due for fn, due in self.fns) - time()*1000
                    if ms_remaining > 0:
                        self.condition.wait(ms_remaining / 1000)

    def add_function(self, f, n):
        with self.lock:
            self.fns.append((f, time() * 1000 + n))
            self.condition.notify_all()

scheduler = Scheduler()
scheduler.add_function(lambda: print("Print"), 10)
scheduler.add_function(lambda: print("Here"), 20)
