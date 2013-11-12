Morphological Processing & Texture Analysis
========

#### PROBLEM 1: MORPHOLOGICAL PROCESSING
In this problem, you are given a binary image I (circle.raw) as shown in Fig. 1. Please follow the instructions below:

- Design a morphological process to extract the objects’ boundaries and output the result as an image M.
- Perform connected component labeling on I to obtain an image L where different objects are labeled with different colors.
- Please design an algorithm based on the morphological operators you learned in class to count the number of circles in image I. Please detail how you solve the overlapping problem.

#### PROBLEM 2: TEXTURE CLASSIFICATION

- The sample images of size 64x64 displayed in Fig 2 are given for this task. Please write a program to categorize them into 4 different types. First, compute the feature of each sample using Law’s method. Then, classify them into different types according to the Law’s features. Please show the classification results in your report and discuss whether the results are correct or not. Notice that it is required to describe the classification algorithm you used in detail.

#### PROBLEM 3: TEXTURE SEGMENTATION
In this problem, you are given a gray-level image I which is composed of several different textures.

- Perform Law’s method on I to obtain the feature vector of each pixel.
- Use k-means algorithm to classify image pixels.
- Label same kind of texture with same gray-level intensity and output the result as L.
- If a wrong k is given in step (b), what will happen? Can you design a method to determine k automatically? Please provide the results and discussions for each part in your report.