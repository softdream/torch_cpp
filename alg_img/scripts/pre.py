from __future__ import print_function, division
import PIL
import torch
from PIL import Image
from torch.autograd import Variable
from torchvision import datasets, transforms
import os
import numpy as np
import cv2
import json

IMAGE_SIZE = (224, 273)
class Model(object):
    def cut_image(self, image, resize=IMAGE_SIZE):
        if isinstance(image, np.ndarray):
            image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
            image = Image.fromarray(image)
        w, h = image.size
        if h == 600 and w == 800:
            he = 70
            we = 120
            t1 = transforms.CenterCrop((h - 2 * he, w - 2 * we))
            image = t1(image)
        t2 = transforms.Resize(resize, interpolation=PIL.Image.CUBIC)
        image = t2(image)
        return image

    def preprocess(self, images):

        normalize=transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
        transform = transforms.Compose([
            transforms.Resize(224),
            transforms.CenterCrop(224),
            transforms.ToTensor(),
            normalize])
        images = [i.copy() for i in images]
        images = [transform(i) for i in images]
        images = torch.stack(images)
        return images
    def get_key(self,dct, value):
        return [k for (k, v) in dct.items() if v == value]
    def pre(self,images):
        os.environ["CUDA_VISIBLE_DEVICES"] = "0"
        f = open('model/label.json', 'r')
        mapping = json.load(f)
        net_name = 'model'
        save_dir = 'model/model'
        modelft_file = save_dir + "/" + net_name + '.pth'
        images = self.preprocess(images)
        model = torch.load(modelft_file,map_location='cpu' )
        model.eval()
        inputs = Variable(images)
        outputs = model(inputs)
        _, preds = torch.max(outputs.data, 1)
        class_name = self.get_key(mapping, preds.tolist()[0])
        return class_name
