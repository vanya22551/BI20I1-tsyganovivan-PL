from django.db import models

# Create your models here.


class Point(models.Model):
    address = models.CharField(max_length=160)
    invite_code = models.CharField(max_length=20, unique=True)
    slug = models.CharField(max_length=130)
    name = models.CharField(max_length=140)