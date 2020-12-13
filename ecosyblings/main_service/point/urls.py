from django.urls import path
from rest_framework.routers import DefaultRouter
from .views import (PointViewSet)


viewsets_router = DefaultRouter()
viewsets_router.register(r'points', PointViewSet, 'points')



urlpatterns = viewsets_router.urls