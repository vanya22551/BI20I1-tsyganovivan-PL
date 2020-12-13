from django.urls import path
from rest_framework.routers import DefaultRouter
from .views import (OrderViewSet)


viewsets_router = DefaultRouter()
viewsets_router.register(r'orders', OrderViewSet, 'orders')



urlpatterns = viewsets_router.urls