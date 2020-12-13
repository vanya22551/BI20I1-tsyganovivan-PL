from django.db import models
import os
from django.conf import settings
from django.contrib.auth.models import User
from point.models import Point
from django.core.validators import MaxValueValidator, MinValueValidator


class Order(models.Model):
    FIRST = 'first'
    SECOND = 'second'
    TIME_TO_REQUEST_CHOICES = [
        (FIRST, '8:00 - 14:00'),
        (SECOND, '14:00 - 20:00'),
    ]
    time_to_request = models.CharField(
        max_length=10,
        choices=TIME_TO_REQUEST_CHOICES,
        default=FIRST,
    )
    date_created = models.DateTimeField(auto_now_add=True)
    user = models.ForeignKey(User, on_delete=models.SET_NULL, null=True, related_name='owner')
    is_taxi = models.BooleanField(default=False)
    point = models.ForeignKey(Point, on_delete=models.SET_NULL, null=True)
    address = models.CharField(max_length=200, null=True)
    is_active = models.BooleanField(default=True)
    courier = models.ForeignKey(User, on_delete=models.SET_NULL, null=True, related_name='courier')
    phone = models.CharField(max_length=13, null=True)
    
    pet = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    pap = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    bottle_glu = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    alu = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    fe = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    total_pet = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    total_pap = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    total_bottle_glu = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    total_alu = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )
    total_fe = models.PositiveIntegerField(
        default=0,
        validators=[
            MinValueValidator(0)
        ]
    )



class OrderPhoto(models.Model):
    order = models.ForeignKey(Order, on_delete=models.CASCADE)
    photo = models.ImageField(upload_to="uploads//%Y/%m/")

