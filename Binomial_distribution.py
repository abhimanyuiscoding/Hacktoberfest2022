# Find the mean and variance of a binomial distribution of number of coin flips (X), probability of heads (Y) and number of samples (N) in it with optional seed value (S)
import numpy as np
import random
from scipy.stats import binom
seed=int(input("Enter seed value: "))
np.random.seed(seed)

X = int(input("Enter number of coin flips: "))
Y = float(input("Enter probability of heads: "))
N = int(input("Enter number of samples: "))
Distribution = np.random.binomial(X,Y,N)
print("Sampled Binomial Distribution is ",Distribution)

print("Mean of the given Binomial Distribution is {:0.2f}".format(np.mean(Distribution)))
print("Variance of the given Binomial Distribution is {:0.2f}".format(np.var(Distribution)))
