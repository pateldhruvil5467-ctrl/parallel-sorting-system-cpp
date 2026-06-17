import matplotlib.pyplot as plt

# Benchmark Data
sizes = [10000, 50000, 100000, 500000, 1000000]

sequential = [
    5440,
    30258,
    63211,
    337233,
    695280
]

parallel = [
    3510,
    11450,
    15682,
    81614,
    166246
]

# Create graph
plt.figure(figsize=(10, 6))

plt.plot(
    sizes,
    sequential,
    marker='o',
    linewidth=2,
    label='Sequential Merge Sort'
)

plt.plot(
    sizes,
    parallel,
    marker='o',
    linewidth=2,
    label='Parallel Merge Sort'
)

plt.title("Sequential vs Parallel Merge Sort Performance")

plt.xlabel("log")

plt.ylabel("Execution Time (Microseconds)")

plt.grid(True)

plt.legend()

plt.tight_layout()

plt.savefig("performance_graph.png")

plt.show()

print("Graph saved as performance_graph.png")