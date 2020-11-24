from django.contrib import admin

# Register your models here.
from .models import Student, Laboratory, Hint, Stats

admin.site.register(Hint)
admin.site.register(Student)
admin.site.register(Laboratory)
admin.site.register(Stats)