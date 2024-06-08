# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.font_manager import FontProperties

def draw_bar(x: np.array, Y: np.array, colors: np.array, labels: list, show: bool, path: str):
    """
    Y is 2D:
        (num_stack, num_years)
    """
    assert(x.shape[0] <= Y.shape[1])
    fig, ax = plt.subplots()
    if not show:
        plt.rcParams['font.sans-serif'] = ['SimHei']
    for i in range(Y.shape[0]):
        offsets = np.sum(Y[:i], axis=0)
        bars = plt.bar(x, Y[i], bottom=offsets, width=0.3, alpha=0.7,color=colors[i]/255., label=labels[i])
        for j in range(x.shape[0]):
            bar = bars[j]
            height = bar.get_height()
            plt.text(bar.get_x() + bar.get_width() / 2.0, height / 2.0 + offsets[j],
                     f"{height}%", ha="center", va="center", color='w', size=15)
            
    plt.xticks(x)
    plt.yticks([])
    ax.spines["top"].set_visible(False)
    ax.spines["left"].set_visible(False)
    ax.spines["right"].set_visible(False)
    plt.legend(loc="upper center", bbox_to_anchor=(0.5, -0.05), fancybox=False, ncol=4)
    if show:
        plt.show()
    else:
        plt.savefig(path, transparent=True, dpi=300)

y1 = [12, 16, 17]
y2 = [13, 14, 18]
y3 = [25, 48, 46]
y4 = [50, 22, 19]
Y = np.array([y1, y2, y3, y4])
x = np.array([2019,2020,2021])
colors = np.array([[74, 117, 180], [89, 140, 215], [135, 170, 234],[185, 203, 241]])
draw_bar(x, Y, colors=colors, labels=["1.5w以上", "1w-1.5w", "4k-1.5w", "4k以下"], show=True, path=r"c:\Data\收入.png")
draw_bar(x, np.array([[45, 38, 46], [29, 36, 31], [17, 18, 16], [9, 8, 7]]), colors=colors, labels=["90后", "80后", "70后", "70前"], show=True, path=r"c:\Data\年龄.png")
"""
y1 = [12, 16, 17]
y2 = [13, 14, 18]
y3 = [25, 48, 46]
y4 = [50, 22, 19]
x = [2019,2020,2021]
y1 = np.array(y1)
y2 = np.array(y2)
y3 = np.array(y3)
y4 = np.array(y4)
fig, ax = plt.subplots()
plt.rcParams['font.sans-serif'] = ['SimHei']
bars = plt.bar(x, y1, width=0.3, alpha=0.7,color=(0, 151 / 255., 168 / 255.), label="1.5w以上")
for bar in bars:
    height = bar.get_height()
    plt.text(bar.get_x() + bar.get_width() / 2.0, height / 2.0, f"{height}%", ha="center", va="center", color='w', size=15)
bars = plt.bar(x, y2, width=0.3, alpha=0.7,bottom=y1, color=(0, 154 / 255., 68 / 255.), label="1w-1.5w")
for i in range(3):
    bar = bars[i]
    height = bar.get_height()
    plt.text(bar.get_x() + bar.get_width() / 2.0, height / 2.0 + y1[i], f"{height}%", ha="center", va="center", color='w', size=15)
bars = plt.bar(x, y3, width=0.3, alpha=0.7,bottom=y1 + y2, color=(134/255., 188 / 255., 40 / 255.), label="4k-1w")
for i in range(3):
    bar = bars[i]
    height = bar.get_height()
    plt.text(bar.get_x() + bar.get_width() / 2.0, height / 2.0 + (y1 + y2)[i], f"{height}%", ha="center", va="center", color='w', size=15)
bars = plt.bar(x, y4, width=0.3, alpha=0.7,bottom=y1 + y2 + y3, color=(208 / 255., 208 / 255., 208 / 255.), label="4k以下")
for i in range(3):
    bar = bars[i]
    height = bar.get_height()
    plt.text(bar.get_x() + bar.get_width() / 2.0, height / 2.0 + (y1 + y2 + y3)[i], f"{height}%", ha="center", va="center", color='w', size=15)
plt.xticks(x)
plt.yticks([])
ax.spines["top"].set_visible(False)
ax.spines["left"].set_visible(False)
ax.spines["right"].set_visible(False)
plt.legend(loc="upper center", bbox_to_anchor=(0.5, -0.05), fancybox=False, ncol=4)
# plt.show()
plt.savefig('c:/Data/d.png', transparent=True, dpi=300)
"""