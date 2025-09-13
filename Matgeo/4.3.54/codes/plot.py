import numpy as np
import matplotlib.pyplot as plt

# Define x range
x = np.linspace(-5, 15, 400)

# Define the lines
y1 = 5*x + 4           # Line 1: 5x - y + 4 = 0
y2 = (4 - 3*x) / 4     # Line 2: 3x + 4y - 4 = 0
y3 = (107*x - 92) / 3  # Line 3: 107x - 3y - 92 = 0

# Intersection points
A = (26/23, 222/23)  # ≈ (1.13, 9.65)
B = (20/23, 8/23)    # ≈ (0.87, 0.35)
M = (1, 5)           # Midpoint

# Plot solid lines
plt.figure(figsize=(8,6))
plt.plot(x, y1, color="blue")
plt.plot(x, y2, color="green")
plt.plot(x, y3, color="red")

# Create dashed proxy lines for legend
l1, = plt.plot([], [], color="blue", linestyle="--", label="5x - y + 4 = 0")
l2, = plt.plot([], [], color="green", linestyle="--", label="3x + 4y - 4 = 0")
l3, = plt.plot([], [], color="red", linestyle="--", label="107x - 3y - 92 = 0")

# Add legend box INSIDE grid
plt.legend(handles=[l1, l2, l3],
           loc="lower right", frameon=True)

# Mark the points A, B, and M (with boxes)
plt.scatter(*A, color="purple", zorder=5)
plt.text(A[0]+0.2, A[1], "A", fontsize=10,
         bbox=dict(facecolor='white', edgecolor='purple'))

plt.scatter(*B, color="orange", zorder=5)
plt.text(B[0]+0.2, B[1], "B", fontsize=10,
         bbox=dict(facecolor='white', edgecolor='orange'))

plt.scatter(*M, color="black", zorder=5)
plt.text(M[0]+0.2, M[1], "M(1,5)", fontsize=10,
         bbox=dict(facecolor='white', edgecolor='black'))

# Axes settings
plt.axhline(0, color='black', linewidth=0.8)
plt.axvline(0, color='black', linewidth=0.8)
plt.xlim(-2, 12)
plt.ylim(-5, 20)

# Labels and grid
plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.title("Plot of Given Lines, Required Line, and Points A, B, M")
plt.grid(True)

# Save and show
plt.savefig("line_plot.png", dpi=300, bbox_inches="tight")
plt.show()

