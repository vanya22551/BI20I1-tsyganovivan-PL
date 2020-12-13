from rest_framework import serializers
from order.models import Order



class OrderSerializer(serializers.ModelSerializer):
    class Meta:
        model = Order
        fields = [
            'id', 
            'user', 
            'is_taxi', 
            'pet', 
            'pap',
            'bottle_glu',
            'alu',
            'fe',
            'time_to_request',
            'date_created',
            'point',
            'address',
            'is_active',
            'courier',
            'phone',
            'total_pet',
            'total_pap',
            'total_bottle_glu',
            'total_alu',
            'total_fe'
            ]
