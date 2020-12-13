from rest_framework import serializers
from point.models import Point



class PointSerializer(serializers.ModelSerializer):
    class Meta:
        model = Point
        fields = ['id', 'address', 'invite_code', 'slug', 'name']



class PointCreateSerializer(serializers.ModelSerializer):
    
    class Meta:
        model = Point
        fields = ['id', 'address', 'slug', 'name']