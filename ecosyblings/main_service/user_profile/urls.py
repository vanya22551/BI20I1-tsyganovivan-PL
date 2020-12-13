from django.urls import path
from rest_framework.routers import DefaultRouter
from .views import (ProfileViewSet)


viewsets_router = DefaultRouter()
viewsets_router.register(r'profiles', ProfileViewSet, 'orders')



urlpatterns = viewsets_router.urls