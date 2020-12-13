from django.shortcuts import render
from order.models import Order
from order.serializers import OrderSerializer
from rest_framework import viewsets
from django.contrib.auth.models import User

class OrderViewSet(viewsets.ModelViewSet):
    serializer_class = OrderSerializer
    queryset = Order.objects.all()
    serializer_actions = {
        'list': OrderSerializer,
        'create': OrderSerializer,
        'retrieve': OrderSerializer,
        'update': OrderSerializer,
        'partial_update': OrderSerializer,
    }

    
    def perform_create(self, serializer):
        save_params = {}
        save_params.update(serializer.validated_data)
        
        if not serializer.validated_data.get('is_taxi'):
            try:
                save_params['point'] = serializer.validated_data.get(
                    'user'
                    ).profile.point
                
            except AttributeError:   
                return
            
        
        serializer.save(**save_params)