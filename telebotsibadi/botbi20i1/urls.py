from django.urls import path

from . import views

urlpatterns = [
    path('', views.facePage, name='Главная страница'),
    path('json_response', views.index, name='index'),
    path('table', views.table_view, name='table'),
    
]