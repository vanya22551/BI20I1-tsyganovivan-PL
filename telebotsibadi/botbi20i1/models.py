from django.db import models
from django.core.validators import MaxValueValidator
from django.db.models.signals import post_save
from django.dispatch import receiver


# Create your models here.


class Laboratory(models.Model):
    description = models.TextField(default="")
    name = models.CharField(max_length=200, default="")

    kt = models.PositiveIntegerField(default=1)

    def __str__(self):
        return self.name


class Student(models.Model):

    group = models.CharField(max_length=20, default="")
    name = models.CharField(max_length=60, default="")
    git_hub = models.CharField(max_length=100, default="")
    rating_1KT = models.PositiveIntegerField(default=0, validators=[
        MaxValueValidator(100)])
    rating_2KT = models.PositiveIntegerField(default=0, validators=[
        MaxValueValidator(100)])
    rating_3KT = models.PositiveIntegerField(default=0, validators=[
        MaxValueValidator(100)])
    rating = models.PositiveIntegerField(default=0, validators=[
        MaxValueValidator(100)])

    labs = models.ManyToManyField(Laboratory, through='Stats')

    def __str__(self):
        return self.group + " " + self.name


@receiver(post_save, sender=Laboratory)
def add_lab_to_student(sender, instance, **kwargs):
    students = Student.objects.all()
    if Stats.objects.filter(lab=instance) is not None:
        for student in students:
            stats = Stats(student=student, lab=instance, status=False)
            stats.save()


class Rating(models.Model):
    name = models.CharField(max_length=30, default="Контрольная точка №1")
    rating = models.PositiveIntegerField(default=0, validators=[
        MaxValueValidator(100)])


class Hint(models.Model):

    text = models.TextField(default="")
    lab = models.ForeignKey(Laboratory, on_delete=models.CASCADE, null=True)

    def __str__(self):
        return self.text


class Stats(models.Model):

    lab = models.ForeignKey(Laboratory, on_delete=models.CASCADE)
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    status = models.BooleanField(default=False)

    def __str__(self):
        return self.lab.name + " " + self.student.name