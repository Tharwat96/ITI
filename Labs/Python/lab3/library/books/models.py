from django.conf.global_settings import MEDIA_URL
from django.db import models

import os

BASE_DIR = os.path.dirname(os.path.dirname(__file__))


# Create your models here.

class Books(models.Model):
    name = models.CharField(max_length=100)
    description = models.TextField(default='No description given yet.')
    cover_pic = models.ImageField(
        default=os.path.join(MEDIA_URL, 'books', '400px600px-r01BookNotPictured.jpg'),
        upload_to='books/')

    def __str__(self):
        return self.name


class Author(models.Model):
    name = models.CharField(max_length=40)
    book_name = models.ManyToManyField(Books, verbose_name="list of books", blank=True, related_name="authors")

    def __str__(self):
        return self.name
