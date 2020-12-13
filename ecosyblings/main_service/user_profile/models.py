from django.db import models
from django.contrib.auth.models import User

from point.models import Point
# Create your models here.


class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    name = models.CharField(max_length=50)
    second_name = models.CharField(max_length=60)
    point = models.ForeignKey(Point, on_delete=models.SET_NULL, null=True)
