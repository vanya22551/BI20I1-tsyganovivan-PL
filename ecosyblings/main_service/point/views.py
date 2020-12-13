from django.shortcuts import render
from point.models import Point
from point.serializers import PointSerializer, PointCreateSerializer
from rest_framework import viewsets

import string, random

class PointViewSet(viewsets.ModelViewSet):
    serializer_class = PointSerializer
    queryset = Point.objects.all()
    serializer_actions = {
        'list': PointSerializer,
        'create': PointCreateSerializer,
        'retrieve': PointSerializer,
        'update': PointSerializer,
        'partial_update': PointSerializer,
    }


    def generate_invite_code(self)->str:
        """Generate a set of unique string tokens.
    
        k: Length of each token
        pool: Iterable of characters to choose from
    
        For a highly optimized version:
        https://stackoverflow.com/a/48421303/7954504
        """
        pool = "ABCDEFGXRTYPOLQMNSZ1234509876"
        k = 8
        token = ''.join(random.choices(pool, k=k))

        return token


    def perform_create(self, serializer):
        serializer.save(invite_code=self.generate_invite_code())