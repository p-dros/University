import numpy as np


class MonitoredArray:
    def __init__(self, start=0, end=1000, elem=100, mode="R"):
        np.random.seed(0)
        if mode == "R":
            self.array = np.linspace(start, end, elem, dtype=np.int64)
            np.random.shuffle(self.array)
        elif mode == "S":
            self.array = np.linspace(start, end, elem, dtype=np.int64)
        elif mode == "A":
            self.array = np.linspace(end, start, elem, dtype=np.int64)
        elif mode == "T":
            __tablica = np.linspace(
                start, (end - start) // 3, elem // 3, dtype=np.int64
            )
            self.array = np.concatenate((__tablica, __tablica, __tablica))
        self.reset()

    def reset(self):
        self.indexes = []
        self.values = []
        self.access_type = []
        self.full_copies = []

    def track(self, key, access_type):
        self.indexes.append(key)
        self.values.append(self.array[key])
        self.access_type.append(access_type)
        self.full_copies.append(np.copy(self.array))

    def activity(self, idx=None):
        if isinstance(idx, type(None)):
            return [(i, op) for (i, op) in zip(self.indexes, self.access_type)]
        else:
            return (self.indexes[idx], self.access_type[idx])

    def __getitem__(self, key):
        self.track(key, "get")
        return self.array.__getitem__(key)

    def __setitem__(self, key, value):
        self.array.__setitem__(key, value)
        self.track(key, "set")

    def __len__(self):
        return self.array.__len__()
