1. std::execution::sequenced_policy:

Oznacza sekwencyjne wykonanie operacji, tj. każda operacja jest wykonywana po kolei, jedna po drugiej, bez równoległości.

2. std::execution::parallel_policy:

Oznacza równoległe wykonanie operacji, tj. operacje mogą być wykonywane równocześnie na różnych wątkach, ale każda operacja w ramach tej polityki musi być zakończona przed rozpoczęciem kolejnej.

3. std::execution::parallel_unsequenced_policy:

Oznacza równoległe wykonanie operacji z dodatkowymi optymalizacjami, pozwalającymi na ich niezależne i nieuporządkowane zakończenie. Może to oznaczać użycie wektorowych instrukcji procesora (SIMD).
