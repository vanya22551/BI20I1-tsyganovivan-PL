from django.urls import path
from django.conf import settings
from django.contrib import admin
from django.conf.urls.static import static
from . import views

urlpatterns = [
    path('', views.facePage, name='Главная страница'),
    path('json_response', views.index, name='index'),
    path('table', views.table_view, name='table'),
    path('api/v1/update_stats_status', views.update_changes, name='update_api'),
    
]+ static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)