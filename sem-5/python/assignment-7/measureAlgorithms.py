from sortingAlgorithms import algorithms
from monitoredArray import MonitoredArray

import time

N = 50
MODES = ["R", "S", "A", "T"]


def get_measurements():
    all_measurements = []

    for algorithm, algorithm_name in algorithms:
        algorithm_measurement = {
            "algorithm_name": algorithm_name,
            "measurements": [],
        }

        for mode in MODES:
            array = MonitoredArray(0, 1000, N, mode)

            t0 = time.perf_counter()
            algorithm(array)
            delta_t = time.perf_counter() - t0

            algorithm_measurement["measurements"].append(
                {
                    "mode": mode,
                    "time": delta_t * 1000,
                    "operations": len(array.full_copies),
                }
            )

        all_measurements.append(algorithm_measurement)

    return all_measurements


def save_measurements_to_file(measurements, filename="measurements.txt"):
    with open(filename, "w") as file:
        for measurement in measurements:
            file.write(f'{measurement["algorithm_name"]}\n')
            for mode_measurement in measurement["measurements"]:
                file.write(
                    f'{mode_measurement["mode"]}: Tablica posortowana w czasie {mode_measurement["time"]:.1f} ms. Liczba operacji: {mode_measurement["operations"]}.\n'
                )
            file.write("\n")


def main():
    measurements = get_measurements()
    save_measurements_to_file(measurements)


if __name__ == "__main__":
    main()
